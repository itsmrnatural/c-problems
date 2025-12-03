# C Programming Practice Repository

A collection of algorithms, data structures, and coding problems which I solved while learning C.

**Compile any program:**

```zsh
clang -Wall -Wextra -std=c99 -o program filename.c -lm
```

## 📚 Implementation

### Algorithms Implemented

- **Sorting**:
  - **Quicksort**:
    - Recursive, functional style ([`quicksort.c`](utils/quicksort.c))
    - In-place, Lomuto partition ([`quicksortv2.c`](utils/quicksortv2.c))
    - Optimized variant ([`quicksortv3.c`](utils/quicksortv3.c))
  - **Merge Sort**: Divide and conquer ([`mergesort.c`](utils/mergesort.c))
  - **Selection Sort**:
    - In-place ([`selectionsortv2.c`](utils/selectionsortv2.c))
    - Non-in-place ([`selectionsort.c`](utils/selectionsort.c))
- **Search**:
  - Binary search in guessing game ([`guessgame.c`](src/guessgame.c))
- **Backtracking**:
  - Random Walk ([`wanderer.c`](src/wanderer.c))
  - Sudoku Solver ([`sudoku.c`](src/sudoku.c))
- **Math & Number Theory**:
  - Sieve of Eratosthenes ([`eratosthenes.c`](src/eratosthenes.c))
  - Magic Square - Siamese Method ([`magicsquare.c`](src/magicsquare.c))
  - Integer Square Root - 3 ways ([`sqrt.c`](utils/sqrt.c))
  - Collatz Conjecture ([`collatz.c`](src/collatz.c))
  - Armstrong Numbers ([`armstrong.c`](src/armstrong.c))
  - Happy Numbers ([`happynum.c`](src/happynum.c))
  - Number Conversion ([`numconv.c`](src/numconv.c))
- **String Processing**:
  - Hamming Distance ([`hamming.c`](src/hamming.c))
  - Readability grading - Coleman-Liau Index ([`readability.c`](src/readability.c))
- **Hashing**:
  - FNV-1a Hash Function ([`fnv1a.c`](utils/fnv1a.c))
- **Stack-Based**:
  - RPN Calculator ([`rpn.c`](src/rpn.c))

### Data Structures Implemented

- **Stack**: Generic implementation with push/pop operations ([`stack.c`](utils/stack.c), [`stack.h`](include/stack.h))
- **Linked List**: Singly linked list with insert/delete/search ([`ll.c`](utils/ll.c), [`linkedlist.h`](include/linkedlist.h))
- **Hash Table**: Open addressing with FNV-1a hashing and linked lists for collision handling ([`ht.c`](utils/ht.c), [`ht.h`](include/ht.h))
- **Graph**: Graph representation (work in progress) ([`graph.h`](include/graph.h))
- **Binary Search Tree**: BST operations (work in progress) ([`bst.c`](utils/bst.c))
- **Dynamic Array**: Resizable array (work in progress) ([`dynarray.c`](utils/dynarray.c))

## 📝 Problems & Algorithms

### Sorting Algorithms

| File                                                | Algorithm      | Time Complexity     | Method                                  |
| --------------------------------------------------- | -------------- | ------------------- | --------------------------------------- |
| [`quicksort.c`](utils/quicksort.c)                  | Quicksort      | O(n log n) avg      | Recursive, functional style with malloc |
| [`quicksortv2.c`](utils/quicksortv2.c)              | Quicksort      | O(n log n) avg      | In-place, Lomuto partition              |
| [`quicksortv3.c`](utils/quicksortv3.c)              | Quicksort      | O(n log n) avg      | Optimized variant                       |
| [`mergesort.c`](utils/mergesort.c)                  | Merge Sort     | O(n log n)          | Divide and conquer, stable              |
| [`selectionsortv2.c`](utils/selectionsortv2.c)      | Selection Sort | O(n²)               | In-place, minimal swaps                 |
| [`selectionsort.c`](utils/selectionsort.c)          | Selection Sort | O(n²)               | Non-in-place (creates new array)        |

### Classic Problems

- **Armstrong Numbers** ([`armstrong.c`](src/armstrong.c)) - Narcissistic number validator
- **Collatz Conjecture** ([`collatz.c`](src/collatz.c)) - Sequence generator with step counter
- **Hamming Distance** ([`hamming.c`](src/hamming.c)) - String difference calculator (DNA sequences)
- **Happy Numbers** ([`happynum.c`](src/happynum.c)) - Detects if number reaches 1 in sum-of-squares sequence
- **Magic Square** ([`magicsquare.c`](src/magicsquare.c)) - Odd-order magic square generator using Siamese method
- **Prime Numbers** ([`eratosthenes.c`](src/eratosthenes.c)) - Sieve of Eratosthenes implementation (O(n log log n))
- **Random Walk** ([`wanderer.c`](src/wanderer.c)) - 10×10 grid path generator (A-Z) with backtracking
- **Seven Segment Display** ([`segmented.c`](src/segmented.c)) - Digital display number renderer

### Puzzles & Games

- **Chess Queen Attack** ([`chesspos.c`](src/chesspos.c)) - Determine if queens can attack each other
- **Guessing Game** ([`guessgame.c`](src/guessgame.c)) - Program guesses number using binary search
- **Sudoku Solver** ([`sudoku.c`](src/sudoku.c)) - Backtracking-based Sudoku puzzle solver

### Practical Applications

- **Flight Scheduler** ([`departure.c`](src/departure.c)) - Closest departure time finder
- **Number Converter** ([`numconv.c`](src/numconv.c)) - Decimal to binary (integer + fractional)
- **Readability Grader** ([`readability.c`](src/readability.c)) - Coleman-Liau index implementation

### Data Structures & Utilities

- **Stack** ([`stack.c`](utils/stack.c)) - Generic stack with test suite ([`test_stack.c`](tests/test_stack.c))
- **Linked List** ([`ll.c`](utils/ll.c)) - Singly linked list with test suite ([`test_linkedlist.c`](tests/test_linkedlist.c))
- **Hash Table** ([`ht.c`](utils/ht.c)) - Hash table using FNV-1a with stress tests ([`stress_hash.c`](tests/stress_hash.c))
- **I/O Utilities** ([`io.c`](utils/io.c)) - Common input/output helper functions

## 🛠️ Development

### Code Formatting

```bash
# Format all files according to .clang-format
clang-format -i src/*.c include/*.h
```

### Adding New Problems

1. Create `src/yourproblem.c`
2. Include necessary headers from [`include/`](include/)
3. Add `main()` function for standalone execution
4. Update this README with problem description

### Style Guidelines

- 4-space indentation (no tabs)
- K&R brace style for control structures
- Left-aligned pointers: `int* ptr`
- Use [`utils.h`](include/utils.h) for common utilities (e.g., `readline()`)

## 📋 Problem Lists

Additional challenging problems are documented in:

- [`interm_problems.md`](interm_problems.md) - Intermediate problems (maze generation, linked lists, etc.)
- [`adv_problems.md`](adv_problems.md) - Advanced problems (N-Queens, Huffman coding, etc.)

### Progress Summary

| List | ✅ Done | 🔄 In Progress | 📋 To Do |
|------|---------|----------------|----------|
| Intermediate | 4 | 0 | 6 |
| Advanced | 1 | 2 | 7 |

## 📄 License

This project is released into the public domain under the [Unlicense](UNLICENSE).
