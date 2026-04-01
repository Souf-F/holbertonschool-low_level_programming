# C - Doubly Linked Lists

## Description

This project is an introduction to **doubly linked lists** in C. Unlike singly linked lists where each node only points to the next one, doubly linked lists have two pointers: one to the **next** node and one to the **previous** node. This allows traversal in both directions.

## Data Structure

```c
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
```

## Files

| File | Description |
|------|-------------|
| `lists.h` | Header file containing all function prototypes and the structure definition |
| `0-print_dlistint.c` | Prints all the elements of a doubly linked list and returns the number of nodes |
| `1-dlistint_len.c` | Returns the number of elements in a doubly linked list |
| `2-add_dnodeint.c` | Adds a new node at the beginning of a doubly linked list |
| `3-add_dnodeint_end.c` | Adds a new node at the end of a doubly linked list |
| `4-free_dlistint.c` | Frees a doubly linked list |
| `5-get_dnodeint.c` | Returns the nth node of a doubly linked list |
| `6-sum_dlistint.c` | Returns the sum of all the data (n) of a doubly linked list |
| `7-insert_dnodeint.c` | Inserts a new node at a given position in a doubly linked list |
| `8-delete_dnodeint.c` | Deletes the node at a given index of a doubly linked list |

## Compilation

All files are compiled on Ubuntu 20.04 LTS using:

```
gcc -Wall -pedantic -Werror -Wextra -std=gnu89
```

## Requirements

- Code follows the Betty style guidelines
- No global variables
- No more than 5 functions per file
- Only allowed C standard library functions: `malloc`, `free`, `printf`, `exit`

## Author

Holberton School project