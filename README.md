# push_swap (42) — Data Structures & Operations Guide

This README focuses on **how to represent stacks using a linked list** and how to implement the core push_swap operations (especially pointer logic). It is written to be practical while coding.

---

## Table of Contents

- [Project Idea (Quick)](#project-idea-quick)
- [Data Structures](#data-structures)
  - [`t_node` (a list node)](#t_node-a-list-node)
  - [`t_list` / Stack wrapper](#t_list--stack-wrapper)
  - [Invariants (Must Always Be True)](#invariants-must-always-be-true)
- [Building Stack A (Append/Tail Method)](#building-stack-a-appendtail-method)
- [Operations Overview](#operations-overview)
- [Core Operations (Detailed Pointer Logic)](#core-operations-detailed-pointer-logic)
  - [`pa` — push top of B to A](#pa--push-top-of-b-to-a)
  - [`pb` — push top of A to B](#pb--push-top-of-a-to-b)
  - [`sa` — swap first 2 elements of A](#sa--swap-first-2-elements-of-a)
  - [`ra` — rotate A up](#ra--rotate-a-up)
  - [`rra` — reverse rotate A](#rra--reverse-rotate-a)
- [Visual Examples](#visual-examples)
  - [Example: `ra` on 3 elements](#example-ra-on-3-elements)
  - [Example: `pa` when A already has elements](#example-pa-when-a-already-has-elements)
- [Common Mistakes (and Why They Break)](#common-mistakes-and-why-they-break)
- [Memory Rules](#memory-rules)
- [Recommended File Layout](#recommended-file-layout)

---

## Project Idea (Quick)

You receive numbers as input and must output a sequence of operations (`sa`, `pb`, `ra`, ...) that sorts them using:

- **Stack A** (initial numbers)
- **Stack B** (initially empty)

Your program does **not** print the sorted numbers directly. It prints the operations that would sort them.

---

## Data Structures

### `t_node` (a list node)

A node represents **one element** in a stack.

```
[ value | prev | next ]
```

Example structure:

- `value`: the integer stored
- `prev`: pointer to the node above it (towards head/top)
- `next`: pointer to the node below it (towards tail/bottom)

---

### `t_list` / Stack wrapper

A stack is represented by a wrapper containing:

- `head` (top of stack)
- `tail` (bottom of stack)
- `size` (# of elements)

```
t_list stack_a;

stack_a.head -> [top] <-> ... <-> [bottom] <- stack_a.tail
stack_a.size = N
```

---

### Invariants (Must Always Be True)

These rules must always hold after every operation:

1. If `size == 0`:
   - `head == NULL`
   - `tail == NULL`

2. If `size == 1`:
   - `head == tail`
   - `head->prev == NULL`
   - `head->next == NULL`

3. If `size >= 2`:
   - `head->prev == NULL`
   - `tail->next == NULL`
   - the list is fully connected by `next` and `prev`

These invariants are your best debugging checklist.

---

## Building Stack A (Append/Tail Method)

You said you want the **Append/Tail** method:

- Iterate input from left to right
- Create one node per number
- Append it to the end (`tail`)
- This preserves input order automatically

Visual:

```
Input:  3   9  -1

A: head -> [3] <-> [9] <-> [-1] <- tail
```

Append logic (conceptually):

- If empty: `head = tail = new`
- Else: link at the end:
  - `new->prev = tail`
  - `tail->next = new`
  - `tail = new`
- `size++`

---

## Operations Overview

push_swap operations manipulate **nodes**, not just values:

- `sa` / `sb`: swap the first 2 nodes of a stack
- `pa`: move top node from B to A
- `pb`: move top node from A to B
- `ra` / `rb`: rotate: top becomes bottom
- `rra` / `rrb`: reverse rotate: bottom becomes top
- `rr`, `ss`, `rrr`: combined operations (do both stacks)

---

## Core Operations (Detailed Pointer Logic)

Below, “A” and “B” are `t_list *`.

### `pa` — push top of B to A

**Goal:** remove `B.head` and make it the new `A.head`.

Before:

```
B: head -> [x] <-> [...] <- tail
A: head -> [a] <-> [b] <-> ... <- tail
```

After `pa`:

```
B: head -> [...] <- tail
A: head -> [x] <-> [a] <-> [b] <-> ... <- tail
```

**Conditions:**
- If `B.size == 0`: do nothing.

**Key idea:** detach node from B, attach node to front of A.

What must be updated:
- `B.head` changes
- maybe `B.tail` changes (if B becomes empty)
- `A.head` changes
- maybe `A.tail` changes (if A was empty)
- `size` updates in both

---

### `pb` — push top of A to B

Same logic as `pa`, just swap roles:

- move `A.head` to become new `B.head`

---

### `sa` — swap first 2 elements of A

If A has at least 2 nodes:

Before:
```
A: head -> [1] <-> [2] <-> [3] ...
```

After `sa`:
```
A: head -> [2] <-> [1] <-> [3] ...
```

You only rearrange the first two nodes and re-link the third (if it exists).

If `A.size < 2`, do nothing.

---

### `ra` — rotate A up

**Meaning:** top element goes to bottom.

Before:
```
A: head -> [1] <-> [2] <-> [3] <- tail
```

After `ra`:
```
A: head -> [2] <-> [3] <-> [1] <- tail
```

**Conditions:**
- If `A.size < 2`: do nothing.

**Logic summary:**
1. Take `first = head`
2. Move `head` to `first->next`
3. Append `first` at tail

Critical pointer requirements after `ra`:
- new `head->prev == NULL`
- new `tail->next == NULL`

---

### `rra` — reverse rotate A

**Meaning:** bottom element goes to top.

Before:
```
A: head -> [1] <-> [2] <-> [3] <- tail
```

After `rra`:
```
A: head -> [3] <-> [1] <-> [2] <- tail
```

**Conditions:**
- If `A.size < 2`: do nothing.

**Logic summary:**
1. Take `last = tail`
2. Move `tail` to `last->prev`
3. Put `last` in front as new head

---

## Visual Examples

### Example: `ra` on 3 elements

Initial:
```
head
 ↓
[10] <-> [20] <-> [30]
                     ↑
                    tail
```

Apply `ra`:
- Detach `[10]` from front
- Attach `[10]` after `[30]`

Result:
```
head
 ↓
[20] <-> [30] <-> [10]
                     ↑
                    tail
```

---

### Example: `pa` when A already has elements

Initial:
```
A: head -> [5] <-> [7] <-> [9]
B: head -> [2] <-> [3]
```

After `pa`:
```
A: head -> [2] <-> [5] <-> [7] <-> [9]
B: head -> [3]
```

Notice: You do **not** manually “shift” A’s values.
Changing `head` pointers automatically shifts the stack logically.

---

## Common Mistakes (and Why They Break)

1. **Passing stacks by value**
   - `do_pa(t_list a, t_list b)` modifies only copies → no real effect.
   - Use pointers: `do_pa(t_list *a, t_list *b)`.

2. **Copying values instead of moving nodes**
   - Operations must move **nodes** to keep structure correct.

3. **Forgetting to update `prev/next`**
   - Especially: `head->prev` must be `NULL`
   - and `tail->next` must be `NULL`

4. **Not handling 0/1 element edge cases**
   - `sa`, `ra`, `rra` must do nothing for `size < 2`
   - `pa/pb` must do nothing if source stack is empty

5. **Wrong free**
   - Never free a node during `pa/pb/ra/...`
   - Only free at program cleanup (or if you explicitly delete nodes, which you typically don’t in push_swap)

---

## Memory Rules

- Nodes are allocated once during parsing / stack creation.
- During operations (`sa`, `pa`, `ra`, ...), you **only change pointers**.
- You free everything at the end:

  - traverse from `head` using `next`
  - free each node
  - set `head = tail = NULL`, `size = 0`

If you use `ft_split`, remember:
- you must free each token and the array.

---

## Recommended File Layout

```
includes/
  push_swap.h

src/
  main.c
  parse/
    parse_args.c
    checks.c
  stack/
    stack_init.c
    stack_append.c
    stack_free.c
  ops/
    op_sa.c
    op_pa.c
    op_ra.c
    op_rra.c
```

This keeps parsing, stack utilities, and operations separated and easier to debug.

---

## Notes

If you want, you can extend this README later with:
- duplicate detection strategy
- indexing / normalization
- sorting logic (small sort for 3/5, radix sort for large)
- complexity notes