# Crash Report — crash_example.c

## Program
`crash_example.c` — NULL pointer dereference leading to segmentation fault

## Environment
- OS: Linux 6.12.67 (ARM64)
- Compiler: gcc `-Wall -Wextra -pedantic -std=gnu89 -g`
- Valgrind: 3.22.0

---

## 1. Confirming the Crash

I compiled and ran the program normally first:

```bash
gcc -Wall -Wextra -pedantic -std=gnu89 -g -o crash_example crash_example.c
./crash_example
```

Output:
```
crash_example: deterministic NULL dereference (segmentation fault)
  requesting n=0
Segmentation fault
```

The program crashes every time. It is fully deterministic — the same input
always produces the same crash.

I then ran it under Valgrind to get more details:

```bash
valgrind --leak-check=full --track-origins=yes -v ./crash_example
```

Valgrind reported:
```
==96205== Invalid write of size 4
==96205==    at 0x10893C: main (crash_example.c:32)
==96205==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==96205== Process terminating with default action of signal 11 (SIGSEGV)
==96205==  Access not within mapped region at address 0x0
```

---

## 2. Identifying the Invalid Memory Access

Looking at the code, I found the problem immediately.

In `main()`, `n` is initialized to `0`:

```c
int n = 0;
```

Then `allocate_numbers(n)` is called with `n = 0`. Inside that function,
there is a guard:

```c
if (n <= 0)
    return NULL;
```

Since `n = 0`, the condition is true and the function returns `NULL` without
calling `malloc()` at all. So `nums` receives `NULL`.

The problem is that `main()` never checks the return value:

```c
nums = allocate_numbers(n);
nums[0] = 42;             /* nums is NULL here — this is the crash */
```

`nums[0] = 42` is equivalent to writing 4 bytes at address `0x0`. That
address is not mapped — the OS protects it on purpose so that NULL dereferences
are caught immediately. The MMU raises a protection fault, the kernel sends
SIGSEGV to the process, and the program terminates.

---

## 3. Full Causal Chain

```
1. n = 0 (initialized in main)

2. allocate_numbers(0) is called
   → guard: if (n <= 0) return NULL
   → no malloc() called
   → returns NULL

3. nums = NULL (address 0x0)

4. nums[0] = 42
   → equivalent to: *(0x0) = 42
   → write of 4 bytes at address 0x0

5. Address 0x0 is not mapped
   → MMU raises protection fault
   → kernel sends SIGSEGV (signal 11)
   → process terminates
```

The crash is not random. Given `n = 0`, it will always happen at exactly
`crash_example.c:32`. Valgrind confirms the faulting address is `0x0` and
that the invalid access is a write of size 4.

---

## 4. Memory Category

The invalid access involves **neither stack nor heap memory**.

- `nums` is a local variable on the stack — it holds the value `NULL` (0x0)
- The write target (`0x0`) is not a stack address and not a heap allocation
- Valgrind confirms: `Address 0x0 is not stack'd, malloc'd or (recently) free'd`

The category of undefined behavior is a **NULL pointer dereference**: writing
through a pointer that holds the value `NULL`.

---

## 5. Secondary Issue — Memory Still Reachable

Valgrind also reported:

```
in use at exit: 1,024 bytes in 1 blocks
still reachable: 1,024 bytes in 1 blocks
```

I looked into this. The 1,024 bytes are not from my code — they are an
internal buffer used by the C standard I/O library (`printf`). When the
process was killed by SIGSEGV, it could not flush or free that buffer. This
is a side effect of the crash, not an independent bug in the program.

---

## 6. AI Analysis — Critical Evaluation

I used an AI tool to generate a first explanation of the crash. Here is what
it said and whether it was correct.

### AI claim 1
> "The segmentation fault is caused by `malloc()` failing because the system
> ran out of memory, which caused it to return NULL."

**This is wrong.**

`malloc()` was never called. `allocate_numbers()` returns NULL before even
reaching the `malloc()` line, because the guard `if (n <= 0) return NULL`
triggers first when `n = 0`. The system did not run out of memory at all.
The AI confused a deliberate early return with a failed allocation. These are
completely different situations with different causes.

### AI claim 2
> "The fix is to change `n` to a positive value before calling
> `allocate_numbers()`."

**This is partially correct but incomplete.**

Changing `n` to a positive value would prevent the crash in this specific
case. But it does not fix the real problem: `main()` never validates the
return value of `allocate_numbers()`. Even with a positive `n`, `malloc()`
could still fail and return NULL if the system is out of memory. The AI
proposed a workaround that only addresses one specific input, not the
underlying design flaw.

The correct fix requires checking the return value regardless of the input.

---

## 7. Suggested Fix

```c
nums = allocate_numbers(n);
if (!nums)
{
    fprintf(stderr, "error: allocation failed or n <= 0 (n=%d)\n", n);
    return 1;
}
nums[0] = 42;
```

And `n` should be set to a meaningful positive value if the intent is to
actually allocate:

```c
int n = 5;
```

Both changes are needed. The `if (!nums)` check makes the program robust
against any NULL return. Changing `n` fixes the logical error of requesting
zero elements.

---

## Summary

| Property | Detail |
|---|---|
| Crash type | Segmentation fault (SIGSEGV) |
| Signal | 11 |
| Faulting address | `0x0` (NULL) |
| Faulting line | `crash_example.c:32` — `nums[0] = 42` |
| Root cause | Missing return value check after `allocate_numbers()` |
| Memory category | Neither stack nor heap — unmapped address |
| Undefined behavior | NULL pointer dereference |
| Deterministic? | Yes — always crashes with `n=0` |
| Secondary issue | 1,024 bytes still reachable (stdio buffer, caused by crash) |