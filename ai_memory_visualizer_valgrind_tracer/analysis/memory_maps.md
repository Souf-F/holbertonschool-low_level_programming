# Memory Maps Analysis

## Programs Analyzed
- `stack_example.c` — recursion and stack frames
- `aliasing_example.c` — pointer aliasing and use-after-free

---

# 1. stack_example.c

## Program Overview

This program demonstrates how stack frames are created and destroyed during recursive function calls. `main()` calls `walk_stack(0, 3)`, which recursively calls itself until `depth == max_depth`.

## Key Execution Points

### Point 1 — `main()` calls `walk_stack(0, 3)`

```
STACK (grows downward)
┌─────────────────────────────────────────┐  HIGH ADDRESS
│                main()                   │
│  (no significant local variables)       │
└─────────────────────────────────────────┘
```

**Variable lifetimes:** `main()` frame exists for the entire program duration.

---

### Point 2 — `walk_stack(depth=0)` calls `dump_frame("enter", 0)`

```
STACK (grows downward)
┌─────────────────────────────────────────┐  HIGH ADDRESS
│                main()                   │
├─────────────────────────────────────────┤
│          walk_stack(depth=0)            │
│  marker = 0        &marker=0xffffcd7fd504  │
├─────────────────────────────────────────┤
│        dump_frame("enter", 0)           │
│  local_int = 100   &local_int=0xffffcd7fd4bc │
│  local_buf[16]     &local_buf=0xffffcd7fd4c8 │
│  p_local = 0xffffcd7fd4bc  ──→ local_int    │
└─────────────────────────────────────────┘  LOW ADDRESS
```

**Variable lifetimes:**
- `marker` lives only during `walk_stack(depth=0)` execution
- `local_int`, `local_buf`, `p_local` live only during `dump_frame()` execution
- When `dump_frame()` returns, its entire frame is destroyed

---

### Point 3 — Full recursion (depth 0 → 3)

```
STACK (grows downward)
┌─────────────────────────────────────────┐  HIGH ADDRESS
│                main()                   │
├─────────────────────────────────────────┤
│       walk_stack(depth=0)               │
│  marker = 0        &marker=0xffffcd7fd504  │
├─────────────────────────────────────────┤
│       walk_stack(depth=1)               │
│  marker = 10       &marker=0xffffcd7fd4d4  │
├─────────────────────────────────────────┤
│       walk_stack(depth=2)               │
│  marker = 20       &marker=0xffffcd7fd4a4  │
├─────────────────────────────────────────┤
│       walk_stack(depth=3)               │
│  marker = 30       &marker=0xffffcd7fd474  │
└─────────────────────────────────────────┘  LOW ADDRESS
```

**Observation from real output:**
Each stack frame is exactly **0x30 = 48 bytes** lower than the previous:
- depth=0: `0xffffcd7fd504`
- depth=1: `0xffffcd7fd4d4` → difference: `0x30` = 48 bytes
- depth=2: `0xffffcd7fd4a4` → difference: `0x30` = 48 bytes
- depth=3: `0xffffcd7fd474` → difference: `0x30` = 48 bytes

The stack grows **toward lower addresses** on this architecture (ARM64/Linux).

---

### Point 4 — Unwinding (exit phase)

```
walk_stack(depth=3) returns → frame DESTROYED, marker=30 no longer exists
walk_stack(depth=2) returns → frame DESTROYED, marker=20 no longer exists
walk_stack(depth=1) returns → frame DESTROYED, marker=10 no longer exists
walk_stack(depth=0) returns → frame DESTROYED, marker=0 no longer exists
main() returns → program ends
```

**Key observation:** At `[exit] depth=N`, the addresses are **identical** to `[enter] depth=N`. This confirms the frame was never moved — it was simply preserved while deeper frames existed on top of it.

---

### Pointer aliasing in `dump_frame()`

```c
int *p_local = &local_int;
```

```
local_int  at 0xffffcd7fd4bc  value=100
p_local    at (some address)  value=0xffffcd7fd4bc  ──→ local_int
```

`p_local` is an alias for `local_int`. Both refer to the same memory cell. This is **stack aliasing** — both variables live in the same stack frame and have the same lifetime.

---

## ⚠️ AI Error — Documented and Corrected

**AI claim:** "Each stack frame is 30 bytes lower than the previous."

**Why this is wrong:** The AI confused hexadecimal and decimal notation. `0x30` is **not** 30 in decimal — it is **48 in decimal** (3 × 16 = 48). The real frame size difference observed in the program output is 48 bytes, not 30.

**Correction:** Each stack frame for `walk_stack()` is **48 bytes (0x30)** lower than the previous, as confirmed by the actual addresses printed by the program.

---

---

# 2. aliasing_example.c

## Program Overview

This program demonstrates pointer aliasing and use-after-free. A heap block is allocated, two pointers are made to point to it, then one pointer is used to free the block while the other continues to access it.

## Key Execution Points

### Point 1 — `main()` starts, before any allocation

```
STACK                              HEAP
┌──────────────────────┐
│       main()         │
│  a = NULL            │
│  b = NULL            │           (empty)
│  n = 5               │
└──────────────────────┘
```

**Variable lifetimes:** `a`, `b`, `n` are local to `main()`. They live until `main()` returns.

---

### Point 2 — `make_numbers(5)` allocates heap memory

```
STACK                              HEAP
┌──────────────────────┐
│       main()         │
│  a = NULL            │
│  b = NULL            │
│  n = 5               │
├──────────────────────┤
│   make_numbers(n=5)  │           malloc(5 * sizeof(int) = 20 bytes)
│  i = 0 → 4          │  ──────→  [ 0 ][ 11 ][ 22 ][ 33 ][ 44 ]
│  arr=0xaaaac34a96b0  │           0xaaaac34a96b0
└──────────────────────┘
```

- `arr` is a local variable in `make_numbers()` — it lives only during that call
- The **heap block** it points to lives independently until `free()` is called
- `make_numbers()` returns `arr` — the heap block survives, the stack frame is destroyed

---

### Point 3 — Back in `main()`: `a = make_numbers(n)` then `b = a`

```
STACK                              HEAP
┌──────────────────────┐
│       main()         │
│  a = 0xaaaac34a96b0 ──────────→ [ 0 ][ 11 ][ 22 ][ 33 ][ 44 ]
│  b = 0xaaaac34a96b0 ──────────→ (same block)
│  n = 5               │           0xaaaac34a96b0
└──────────────────────┘
```

**Pointer aliasing:** `a` and `b` are **aliases** — they hold the same address and point to the exact same heap block. Modifying memory through `a` affects what `b` sees, and vice versa.

Output confirms: `a=0xaaaac34a96b0 b=0xaaaac34a96b0`

---

### Point 4 — `free(a)` is called

```
STACK                              HEAP
┌──────────────────────┐
│       main()         │
│  a = 0xaaaac34a96b0 ──────────→ [FREED — memory returned to allocator]
│  b = 0xaaaac34a96b0 ──────────→ (dangling pointer — same invalid address)
│  n = 5               │
└──────────────────────┘
```

**Critical facts:**
- `free(a)` releases the heap block — the memory no longer belongs to the program
- `a` still contains `0xaaaac34a96b0` — `free()` does NOT set the pointer to NULL
- `b` still contains `0xaaaac34a96b0` — `b` was never notified of the `free()`
- Both `a` and `b` are now **dangling pointers**

---

### Point 5 — Reading `b[2]` after `free(a)`

```
STACK                              HEAP
┌──────────────────────┐
│  b = 0xaaaac34a96b0 ──────────→ [FREED]
└──────────────────────┘                ↑
                                   b[2] read → 761897794 (garbage value)
                                   USE-AFTER-FREE (invalid read)
```

The value `761897794` is garbage — it reflects whatever the memory allocator wrote into that block after freeing it. This is **undefined behavior**: the program might crash, return garbage, or appear to work correctly depending on the system state.

---

### Point 6 — Writing `b[3] = 1234`

```
STACK                              HEAP
┌──────────────────────┐
│  b = 0xaaaac34a96b0 ──────────→ [FREED]
└──────────────────────┘                ↑
                                   b[3] = 1234
                                   USE-AFTER-FREE (invalid write)
```

Writing to freed memory is even more dangerous than reading. It can corrupt the allocator's internal bookkeeping structures, leading to crashes or security vulnerabilities later in the program.

---

## ⚠️ AI Error — Documented and Corrected

**AI claim:** "When `free(a)` is called, `a` becomes NULL automatically."

**Why this is wrong:** This is a common misconception. The C standard does not specify that `free()` modifies the pointer passed to it. `free()` only releases the memory block. After `free(a)`:
- `a` still holds the value `0xaaaac34a96b0`
- `b` also still holds `0xaaaac34a96b0`
- Neither pointer is NULL

This is precisely why use-after-free bugs are so dangerous — the pointer looks valid (non-NULL) but the memory it references is no longer owned by the program.

**Correction:** After `free(a)`, both `a` and `b` remain **dangling pointers** with the original address. To prevent accidental use, the programmer must manually set `a = NULL` after calling `free(a)`. However, this would not fix `b`, which remains dangling.

---

---

# Summary Table

| Program | Memory Region | Bug Type | Explanation |
|---|---|---|---|
| `stack_example` | Stack | None (correct behavior) | Stack frames created/destroyed correctly with recursion |
| `aliasing_example` | Heap | Use-after-free | `b` aliases `a`, `free(a)` invalidates both, `b` still accessed |
| `aliasing_example` | Stack | None | Local variables in `main()` behave correctly |

---

# Key Takeaways

1. **Stack variables** have automatic lifetimes — they are destroyed when their function returns. Never return a pointer to a local variable.

2. **Heap variables** have manual lifetimes — they live until `free()` is called, regardless of which pointer is used to free them.

3. **Pointer aliasing** means multiple pointers can own the same memory. When one is freed, all aliases become dangling.

4. **`free()` does not set the pointer to NULL.** The programmer is responsible for setting it to NULL after freeing if needed.

5. **Use-after-free** produces undefined behavior — reads return garbage values, writes can corrupt allocator internals.