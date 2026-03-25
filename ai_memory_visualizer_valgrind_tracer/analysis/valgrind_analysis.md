# Valgrind Analysis

## Programs Analyzed
- `heap_example` — deliberate memory leak
- `aliasing_example` — pointer aliasing and use-after-free

---

# 1. heap_example

## Valgrind Command Used
```bash
valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -v ./heap_example
```

## Valgrind Output (relevant section)
```
==68644== 6 bytes in 1 blocks are definitely lost in loss record 1 of 1
==68644==    at 0x4885250: malloc (vgpreload_memcheck-arm64-linux.so)
==68644==    by 0x1088BF: person_new (heap_example.c:21)
==68644==    by 0x1089BB: main (heap_example.c:51)

LEAK SUMMARY:
   definitely lost: 6 bytes in 1 blocks
ERROR SUMMARY: 1 errors from 1 contexts
```

---

## Error Classification

| # | Type | Location | Memory Object |
|---|------|----------|---------------|
| 1 | Memory leak (definitely lost) | `heap_example.c:21` | `alice->name` (6 bytes) |

---

## Detailed Analysis

### Error 1 — Memory Leak: `alice->name` never freed

**Type:** Definite memory leak — lost ownership

**Memory object involved:**
- `alice->name` is a heap block of 6 bytes allocated in `person_new()` at line 21
- It holds the string `"Alice\0"` (5 characters + null terminator = 6 bytes)

**Memory layout at the time of the leak:**

```
HEAP
┌──────────────────────────────────────┐
│  alice  (sizeof(Person) bytes)       │  ← freed by person_free_partial()
│    name ──→ [ A ][ l ][ i ][ c ][ e ][ \0 ]  ← NEVER FREED (6 bytes leaked)
│    age  = 30                         │
└──────────────────────────────────────┘

┌──────────────────────────────────────┐
│  bob  (sizeof(Person) bytes)         │  ← freed correctly
│    name ──→ [ B ][ o ][ b ][ \0 ]   │  ← freed correctly
│    age  = 41                         │
└──────────────────────────────────────┘
```

**Root cause — lifetime violation:**

`person_free_partial()` only frees the `Person` struct itself:
```c
static void person_free_partial(Person *p)
{
    if (!p)
        return;
    free(p);   /* frees the struct — but NOT p->name */
}
```

When `person_free_partial(alice)` is called:
1. `alice` (the `Person` struct) is freed ✓
2. `alice->name` (the heap block holding `"Alice\0"`) is **never freed** ✗

After `free(alice)`, the pointer to `alice->name` is lost forever — no variable in the program still holds that address. The memory allocator cannot reclaim it. This is **lost ownership**: the only pointer that could free `alice->name` was stored inside `alice`, which was freed before `alice->name` was released.

**Correct fix would be:**
```c
/* Free name first, then the struct */
free(alice->name);
free(alice);
```

**Why `bob` had no leak:**
`bob->name` and `bob` were freed manually and in the correct order:
```c
free(bob->name);  /* name freed first */
free(bob);        /* then the struct */
```

**Valgrind trace explanation:**
```
at malloc        ← where alice->name was allocated
by person_new (heap_example.c:21)  ← line: p->name = malloc(len + 1)
by main (heap_example.c:51)        ← line: alice = person_new("Alice", 30)
```
Valgrind tracked the allocation back to its origin and confirmed no matching `free()` was ever called for that block.

---

## ⚠️ AI Error — Documented and Corrected

**AI claim:** "The leak is caused because `person_free_partial()` was not called for `bob`."

**Why this is wrong:** `bob` was freed correctly — `free(bob->name)` and `free(bob)` were both called explicitly in `main()`. The leak only affects `alice`, because `person_free_partial()` frees the `Person` struct but not its `name` field. The AI confused which `Person` object was leaking and misidentified the root cause.

**Correction:** The leak is caused by `person_free_partial()` freeing `alice` (the struct) without first freeing `alice->name`. The `name` field is a separate heap allocation that must be freed independently before the struct is freed. Once the struct is freed, the address of `name` is permanently lost.

---

---

# 2. aliasing_example

## Valgrind Command Used
```bash
valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -v ./aliasing_example
```

## Valgrind Output (relevant section)
```
==68757== Invalid read of size 4
==68757==    at 0x108994: main (aliasing_example.c:42)
==68757==  Address 0x4a7e488 is 8 bytes inside a block of size 20 free'd

==68757== Invalid write of size 4
==68757==    at 0x1089B4: main (aliasing_example.c:44)
==68757==  Address 0x4a7e48c is 12 bytes inside a block of size 20 free'd

==68757== Invalid read of size 4
==68757==    at 0x1089C0: main (aliasing_example.c:45)
==68757==  Address 0x4a7e48c is 12 bytes inside a block of size 20 free'd

HEAP SUMMARY:
    in use at exit: 0 bytes in 0 blocks
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 3 errors from 3 contexts
```

---

## Error Classification

| # | Type | Line | Address | Memory Object |
|---|------|------|---------|---------------|
| 1 | Invalid read (use-after-free) | `aliasing_example.c:42` | `0x4a7e488` (+8 bytes) | `b[2]` — freed block |
| 2 | Invalid write (use-after-free) | `aliasing_example.c:44` | `0x4a7e48c` (+12 bytes) | `b[3]` — freed block |
| 3 | Invalid read (use-after-free) | `aliasing_example.c:45` | `0x4a7e48c` (+12 bytes) | `b[3]` — freed block |

---

## Detailed Analysis

### Memory layout before `free(a)`

```
STACK                              HEAP
┌──────────────────────┐
│       main()         │           malloc(5 * sizeof(int) = 20 bytes)
│  a = 0x4a7e480 ──────────────→  [ 0 ][ 11 ][ 22 ][ 33 ][ 44 ]
│  b = 0x4a7e480 ──────────────→  (same block — alias)
│  n = 5               │           +0   +4    +8    +12   +16
└──────────────────────┘           b[0] b[1]  b[2]  b[3]  b[4]
```

`a` and `b` are aliases — they hold the same address `0x4a7e480`.

---

### Error 1 — Invalid read at `aliasing_example.c:42`

**Code:**
```c
printf("  reading b[2]=%d\n", b[2]);
```

**Type:** Invalid read of size 4 — use-after-free

**Memory object:** `b[2]` — located at `0x4a7e480 + 8 = 0x4a7e488`

**Lifetime violation:**
- The heap block at `0x4a7e480` was freed at line 38 via `free(a)`
- `b` still holds the address `0x4a7e480` — it was never updated
- Reading `b[2]` accesses `0x4a7e488`, which is 8 bytes inside a freed block
- The memory no longer belongs to the program — reading it is undefined behavior

**Why Valgrind says "8 bytes inside a block of size 20 free'd":**
- Block starts at `0x4a7e480`
- `b[2]` is at offset `2 * sizeof(int) = 8` bytes from the start
- So `0x4a7e488 = 0x4a7e480 + 8` — confirmed by Valgrind

---

### Error 2 — Invalid write at `aliasing_example.c:44`

**Code:**
```c
b[3] = 1234;
```

**Type:** Invalid write of size 4 — use-after-free

**Memory object:** `b[3]` — located at `0x4a7e480 + 12 = 0x4a7e48c`

**Lifetime violation:**
- Same freed block at `0x4a7e480`
- `b[3]` is at offset `3 * sizeof(int) = 12` bytes
- Writing to freed memory can corrupt the memory allocator's internal bookkeeping structures
- This may cause crashes, silent data corruption, or security vulnerabilities in later allocations

---

### Error 3 — Invalid read at `aliasing_example.c:45`

**Code:**
```c
printf("  wrote b[3]=%d\n", b[3]);
```

**Type:** Invalid read of size 4 — use-after-free

**Memory object:** `b[3]` — same address `0x4a7e48c` as Error 2

**Lifetime violation:**
- Reading back the value just written to freed memory
- Even though the write "appeared to work" (the program printed `1234`), both the write and this read are undefined behavior

---

### Why there is NO memory leak in `aliasing_example`

Valgrind reports: `All heap blocks were freed -- no leaks are possible`

The single heap block allocated by `make_numbers()` was freed via `free(a)` at line 38. Even though `b` still points to that address, the block was correctly released. The issue is not a leak — it is that the block was accessed **after** being freed.

---

### Full causal chain

```
1. make_numbers(5) → malloc(20 bytes) at 0x4a7e480
2. a = 0x4a7e480
3. b = a → b = 0x4a7e480 (alias created)
4. free(a) → block at 0x4a7e480 is released
             a and b still hold 0x4a7e480 (dangling pointers)
5. b[2] read → address 0x4a7e488 → INVALID READ (Error 1)
6. b[3] = 1234 → address 0x4a7e48c → INVALID WRITE (Error 2)
7. b[3] read → address 0x4a7e48c → INVALID READ (Error 3)
```

---

## ⚠️ AI Error — Documented and Corrected

**AI claim:** "Valgrind reports a use-after-free because `b` was not set to NULL after `free(a)`. Setting `b = NULL` after `free(a)` would have prevented the error."

**Why this is wrong:** Setting `b = NULL` after `free(a)` would indeed prevent the accesses — but only because it would cause a **segmentation fault** instead of a use-after-free. That is not a fix; it is just a different crash. The real fix requires eliminating the alias before freeing, or ensuring no pointer accesses the block after it is freed. Furthermore, Valgrind does not report the error because `b` is non-NULL — it reports it because the accessed memory address belongs to a freed block. Valgrind tracks the state of heap blocks, not the values of pointers.

**Correction:** The use-after-free occurs because `b` is an alias of `a` — both point to the same heap block. When `free(a)` is called, the block is released, but `b` is not updated. The program then uses `b` to read and write that freed block. The root cause is **lost ownership tracking**: the program does not know that `b` and `a` share ownership, so freeing through `a` silently invalidates `b`.

---

---

# Summary Table

| Program | Error Type | Line | Memory Object | Cause |
|---|---|---|---|---|
| `heap_example` | Definite memory leak | 21 / 51 | `alice->name` (6 bytes) | `person_free_partial()` frees struct but not `name` field |
| `aliasing_example` | Invalid read (use-after-free) | 42 | `b[2]` at `0x4a7e488` | `b` aliases freed block |
| `aliasing_example` | Invalid write (use-after-free) | 44 | `b[3]` at `0x4a7e48c` | `b` aliases freed block |
| `aliasing_example` | Invalid read (use-after-free) | 45 | `b[3]` at `0x4a7e48c` | `b` aliases freed block |

---

# Key Takeaways

1. **Valgrind does not find bugs by magic.** Every reported issue maps to a specific memory misuse with a precise address and a traceable allocation origin.

2. **"Definitely lost"** means the only pointer that could free the block was itself freed or went out of scope before the block was released. Ownership was permanently lost.

3. **Use-after-free** happens when a pointer alias survives a `free()` call. The freed block is no longer valid, but the dangling pointer looks non-NULL and valid.

4. **Invalid write is more dangerous than invalid read.** Writing to freed memory can corrupt the allocator's internal structures, causing crashes or silent data corruption in completely unrelated parts of the program.

5. **No leak does not mean no errors.** `aliasing_example` had zero leaks but three serious memory errors. Valgrind categories are independent.