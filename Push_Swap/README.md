*This activity has been created as part of the 42 curriculum by <sarakely>, <sayeghia>*

# Push Swap – Adaptive Sorting Project

## Description

This project implements an efficient sorting program using a limited set of stack operations, as defined in the 42 **push_swap** subject. The goal is to sort a list of integers with the smallest possible number of operations, using two stacks (`a` and `b`) and a predefined instruction set.

The project introduces an **adaptive sorting system** that dynamically selects the most appropriate algorithm based on the level of disorder in the input data. It combines multiple strategies to optimize performance across different input sizes and distributions.

---

## Instructions

### Compilation

To compile the main program:

```bash
make
```

To compile the bonus checker:

```bash
make bonus
```

To clean object files:

```bash
make clean
```

To remove all binaries:

```bash
make fclean
```

To recompile everything:

```bash
make re
```

---

### Execution

Run the sorting program:

```bash
./push_swap [options] <numbers>
```

Example:

```bash
./push_swap 3 2 1 5 4
```

#### Available Flags

* `--simple` → Force simple O(n²) algorithm
* `--medium` → Force medium O(n√n) algorithm
* `--complex` → Force complex O(n log n) algorithm
* `--adaptive` → Default: automatically selects best strategy
* `--bench` → Display benchmarking statistics
* `--count-only` → Output only the number of operations

---

### Checker (Bonus)

```bash
./checker <numbers>
```

Then input operations via stdin:

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

Outputs:

* `OK` if sorted correctly
* `KO` otherwise

---

## Algorithms & Strategy Justification

This project implements four sorting strategies, each chosen based on input size and disorder level:

### 1. Simple Sort — O(n²)

* Strategy: Selection-like approach using minimum extraction
* Best for: Small or nearly sorted datasets
* Reason: Low overhead and minimal stack operations for small inputs

---

### 2. Medium Sort — O(n√n)

* Strategy: Chunk-based sorting
* Splits the dataset into √n chunks
* Moves elements between stacks in controlled batches
* Best for: Moderately sized inputs
* Reason: Reduces unnecessary rotations and balances complexity vs efficiency

---

### 3. Complex Sort — O(n log n)

* Strategy: Radix sort based on binary representation of indexed values
* Uses bitwise operations to distribute elements
* Best for: Large datasets
* Reason: Deterministic performance with predictable operation count

---

### 4. Adaptive Strategy

* Strategy: Dynamically selects algorithm based on **disorder metric**
* Disorder is computed as:

  * Ratio of inverted pairs to total possible pairs
* Thresholds:

  * `< 0.2` → Simple sort
  * `< 0.5` → Medium sort
  * `>= 0.5` → Complex sort

**Justification:**

* Avoids worst-case inefficiencies
* Matches algorithm complexity to real input characteristics
* Improves average performance significantly

---

## Resources

### Documentation & References

* 42 Subject: push_swap
* Stack data structures and algorithms
* Radix sort and chunk-based sorting techniques
* Time complexity analysis (Big-O notation)

### AI Usage

AI tools were used in the following ways:

* Assisting in understanding algorithm trade-offs (O(n²), O(n√n), O(n log n))
* Helping design the adaptive strategy thresholds
* Providing explanations and validation for edge cases
* Supporting debugging and optimization discussions

All implementation, testing, and final decisions were made by the authors.

---

## Contributions

### sarakely

* Core architecture design
* Implementation of:

  * Simple sorting algorithms
  * Adaptive sorting system
  * Complex (radix) algorithm
  * Benchmarking system
* Input parsing and validation
* Makefile and project structure

---

### sayeghia

* Implementation of:

  * Medium sorting algorithm
  * Stack operations and utilities
* Optimization of chunk-based logic
* Testing and edge case validation
* Checker (bonus) integration and validation logic

---

## Additional Notes

* The program minimizes the number of operations while ensuring correctness.
* Benchmark mode allows performance analysis of different strategies.
* The project is fully modular and extensible for future improvements.

---
