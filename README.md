# Push_Swap

*This project has been created as part of the 42 curriculum by lunsold.*

---

## 📋 Table of Contents

- [Description](#description)
- [The Challenge](#the-challenge)
- [Stack Operations](#stack-operations)
- [Visual Examples](#visual-examples)
- [Program Specifications](#program-specifications)
- [Performance Requirements](#performance-requirements)
- [Bonus: Checker Program](#bonus-checker-program)
- [Instructions](#instructions)
- [Resources](#resources)

---

## 🎯 Description

**Push_Swap** is an algorithmic challenge focused on sorting data efficiently using a limited set of operations. The project requires you to:

- Sort a stack of random integers in **ascending order**
- Use only **two stacks** (stack `a` and stack `b`)
- Execute a **limited set of stack operations**
- Minimize the total number of operations required

The goal is not just to sort the numbers, but to find the **most efficient sequence** of operations that accomplishes the task. This project introduces fundamental concepts of algorithmic complexity and optimization.

### Why This Matters

Sorting algorithms are a cornerstone of computer science and frequently appear in technical interviews. This project provides hands-on experience with:

- **Algorithm design** and optimization
- **Complexity analysis** (time and space)
- **Data structure manipulation**
- **Problem-solving** under constraints

---

## 🎲 The Challenge

### Initial State

At the start of the program:

- **Stack A** contains a random amount of unique integers (positive and/or negative)
- **Stack B** is empty

### Goal

Sort all numbers in **stack A** in **ascending order** (smallest on top), using only the operations described below.

### Example

```
Input:  2 1 3 6 5 8

Initial State:
┌───┐  ┌───┐
│ 2 │  │   │
│ 1 │  │   │
│ 3 │  │   │
│ 6 │  │   │
│ 5 │  │   │
│ 8 │  │   │
└───┘  └───┘
  a      b

Goal:
┌───┐  ┌───┐
│ 1 │  │   │
│ 2 │  │   │
│ 3 │  │   │
│ 5 │  │   │
│ 6 │  │   │
│ 8 │  │   │
└───┘  └───┘
  a      b
```

---

## 🔧 Stack Operations

You have **11 operations** at your disposal to manipulate the stacks:

### Swap Operations

| Operation | Description |
|-----------|-------------|
| `sa` | **Swap a** - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements. |
| `sb` | **Swap b** - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements. |
| `ss` | **Swap both** - Execute `sa` and `sb` simultaneously. |

### Push Operations

| Operation | Description |
|-----------|-------------|
| `pa` | **Push to a** - Take the first element at the top of B and put it on top of A. Do nothing if B is empty. |
| `pb` | **Push to b** - Take the first element at the top of A and put it on top of B. Do nothing if A is empty. |

### Rotate Operations

| Operation | Description |
|-----------|-------------|
| `ra` | **Rotate a** - Shift all elements of stack A **up** by 1. The first element becomes the last. |
| `rb` | **Rotate b** - Shift all elements of stack B **up** by 1. The first element becomes the last. |
| `rr` | **Rotate both** - Execute `ra` and `rb` simultaneously. |

### Reverse Rotate Operations

| Operation | Description |
|-----------|-------------|
| `rra` | **Reverse rotate a** - Shift all elements of stack A **down** by 1. The last element becomes the first. |
| `rrb` | **Reverse rotate b** - Shift all elements of stack B **down** by 1. The last element becomes the first. |
| `rrr` | **Reverse rotate both** - Execute `rra` and `rrb` simultaneously. |

---

## 📊 Visual Examples

### Example 1: Swap Operation (`sa`)

```
Before sa:           After sa:
┌───┐  ┌───┐        ┌───┐  ┌───┐
│ 2 │  │   │        │ 1 │  │   │  ← Elements swapped
│ 1 │  │   │        │ 2 │  │   │  ←
│ 3 │  │   │        │ 3 │  │   │
│ 6 │  │   │        │ 6 │  │   │
│ 5 │  │   │        │ 5 │  │   │
│ 8 │  │   │        │ 8 │  │   │
└───┘  └───┘        └───┘  └───┘
  a      b            a      b
```

### Example 2: Push Operation (`pb`)

```
Before pb:           After pb:
┌───┐  ┌───┐        ┌───┐  ┌───┐
│ 2 │  │   │        │ 1 │  │ 2 │  ← Top of A moved to B
│ 1 │  │   │        │ 3 │  │   │
│ 3 │  │   │        │ 6 │  │   │
│ 6 │  │   │        │ 5 │  │   │
│ 5 │  │   │        │ 8 │  │   │
│ 8 │  │   │        └───┘  └───┘
└───┘  └───┘          a      b
  a      b
```

### Example 3: Rotate Operation (`ra`)

```
Before ra:           After ra:
┌───┐  ┌───┐        ┌───┐  ┌───┐
│ 1 │  │   │        │ 2 │  │   │
│ 2 │  │   │        │ 3 │  │   │
│ 3 │  │   │        │ 1 │  │   │  ← First became last
└───┘  └───┘        └───┘  └───┘
  a      b            a      b
```

### Example 4: Reverse Rotate Operation (`rra`)

```
Before rra:          After rra:
┌───┐  ┌───┐        ┌───┐  ┌───┐
│ 1 │  │   │        │ 3 │  │   │  ← Last became first
│ 2 │  │   │        │ 1 │  │   │
│ 3 │  │   │        │ 2 │  │   │
└───┘  └───┘        └───┘  └───┘
  a      b            a      b
```

### Complete Sorting Example

Let's sort `2 1 3 6 5 8` step by step:

```
┌─────────────────────────────────────────────┐
│ Initial State                               │
├─────────────────────────────────────────────┤
│  a: [ 2  1  3  6  5  8 ]                   │
│  b: [                  ]                    │
└─────────────────────────────────────────────┘

Execute: sa (swap first two in A)
┌─────────────────────────────────────────────┐
│  a: [ 1  2  3  6  5  8 ]                   │
│  b: [                  ]                    │
└─────────────────────────────────────────────┘

Execute: pb pb pb (push 1, 2, 3 to B)
┌─────────────────────────────────────────────┐
│  a: [ 6  5  8 ]                             │
│  b: [ 3  2  1 ]                             │
└─────────────────────────────────────────────┘

Execute: ra (rotate A)
┌─────────────────────────────────────────────┐
│  a: [ 5  8  6 ]                             │
│  b: [ 3  2  1 ]                             │
└─────────────────────────────────────────────┘

Execute: rb (rotate B)
┌─────────────────────────────────────────────┐
│  a: [ 5  8  6 ]                             │
│  b: [ 2  1  3 ]                             │
└─────────────────────────────────────────────┘

Execute: rra (reverse rotate A)
┌─────────────────────────────────────────────┐
│  a: [ 6  5  8 ]                             │
│  b: [ 2  1  3 ]                             │
└─────────────────────────────────────────────┘

Execute: rrb (reverse rotate B)
┌─────────────────────────────────────────────┐
│  a: [ 6  5  8 ]                             │
│  b: [ 3  2  1 ]                             │
└─────────────────────────────────────────────┘

Execute: sa (swap first two in A)
┌─────────────────────────────────────────────┐
│  a: [ 5  6  8 ]                             │
│  b: [ 3  2  1 ]                             │
└─────────────────────────────────────────────┘

Execute: pa pa pa (push all from B to A)
┌─────────────────────────────────────────────┐
│  a: [ 1  2  3  5  6  8 ]  ✓ SORTED!        │
│  b: [                  ]                    │
└─────────────────────────────────────────────┘

Total: 12 operations
```

**Can you do better?** This is the essence of the Push_Swap challenge!

---

## 💻 Program Specifications

### push_swap

**Program Name:** `push_swap`

**Usage:**
```bash
./push_swap <list of integers>
```

**Description:**

The program takes a list of integers as arguments and outputs the **shortest sequence** of operations needed to sort stack A in ascending order.

**Output:**
- Each operation is printed on a new line
- Operations must be separated by `\n` and nothing else
- No output if no parameters are given
- `Error\n` to stderr for invalid input

**Error Cases:**
- Arguments that are not integers
- Arguments exceeding integer limits (`INT_MIN` to `INT_MAX`)
- Duplicate numbers

**Examples:**

```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa

$ ./push_swap 0 one 2 3
Error

$ ./push_swap
$
```

**Testing with checker:**

```bash
$ ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6

$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
```

---

## 📈 Performance Requirements

Your sorting algorithm's efficiency is measured by the number of operations required:

### For 100% Validation (and Bonus Eligibility)

| Test Case | Maximum Operations |
|-----------|-------------------|
| 100 random numbers | < **700 operations** |
| 500 random numbers | < **5500 operations** |

### For 80% Validation (Minimum Pass)

Different combinations are acceptable:

| 100 Numbers | 500 Numbers | Result |
|-------------|-------------|---------|
| < 1100 ops  | < 8500 ops  | 80% |
| < 700 ops   | < 11500 ops | 80% |
| < 1300 ops  | < 5500 ops  | 80% |

### Special Cases

| Test Case | Requirement |
|-----------|-------------|
| 3 numbers | ≤ **3 operations** |
| 5 numbers | ≤ **12 operations** |

---

## 🎁 Bonus: Checker Program

The bonus part includes implementing your own **checker** program.

**Program Name:** `checker`

**Usage:**
```bash
./checker <list of integers>
```

**Description:**

The checker reads operations from standard input and executes them on the given stack. After execution, it verifies if stack A is sorted.

**Output:**
- `OK\n` if stack A is sorted in ascending order and stack B is empty
- `KO\n` if the stack is not sorted or B is not empty
- `Error\n` to stderr for invalid input or operations

**Examples:**

```bash
$ ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK

$ ./checker 3 2 1 0
sa
rra
pb
KO

$ ./checker 3 2 one 0
Error
```

---

## 🚀 Instructions

### Compilation

```bash
# Compile push_swap
make

# Compile with bonus (checker)
make bonus

# Clean object files
make clean

# Full clean
make fclean

# Recompile
make re
```

### Usage

**Basic usage:**
```bash
./push_swap 3 2 1 0 -42 789
```

**With single string argument:**
```bash
./push_swap "3 2 1 0 -42 789"
```

**Test efficiency:**
```bash
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | wc -l
```

**Verify correctness:**
```bash
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | ./checker $ARG
```

### Testing

**Generate random numbers:**
```bash
# macOS
ARG=$(jot -r 100 -2147483648 2147483647 | tr '\n' ' ')

# Linux
ARG=$(shuf -i -2147483648-2147483647 -n 100 | tr '\n' ' ')
```

**Test performance:**
```bash
# Test 100 numbers
for i in {1..10}; do
  ARG=$(seq 1 100 | shuf | tr '\n' ' ')
  echo "Test $i: $(./push_swap $ARG | wc -l) operations"
done
```

---

**Good luck sorting!** 🎲

