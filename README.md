# C Programming Practice Repository

A collection of algorithms, data structures, and coding problems which I solved while learning C.

**Compile any program:**

```zsh
clang -Wall -Wextra -std=c99 -o program filename.c -lm
```

## 📚 Implementation

### Algorithms Implemented

-   **Divide & Conquer**: Quicksort ([`quicksort.c`](src/quicksort.c), [`quicksortv2.c`](src/quicksortv2.c))
-   **Comparison Sorting**: Selection Sort ([`selectionsortv2.c`](src/selectionsortv2.c), [`selectionsort.c`](src/selectionsort.c))
-   **Backtracking**: Random Walk ([`wanderer.c`](src/wanderer.c)), Sudoku Solver ([`sudoku.c`](src/sudoku.c))
-   **Iteration & Recursion**:
    -   Hamming Distance ([`hamming.c`](src/hamming.c))
    -   Number Conversion ([`numconv.c`](src/numconv.c))
    -   Collatz Conjecture ([`collatz.c`](src/collatz.c))
    -   Armstrong Numbers ([`armstrong.c`](src/armstrong.c))
    -   Happy Numbers ([`happynum.c`](src/happynum.c))
-   **Mathematical Algorithms**: Magic Square - Siamese Method ([`magicsquare.c`](src/magicsquare.c))
-   **Stack-Based**: RPN Calculator ([`rpn.c`](src/rpn.c))
-   **String Processing**: Readability grading - Coleman-Liau Index ([`readability.c`](src/readability.c))
-   **Search Algorithms**: Binary search in guessing game ([`guessgame.c`](src/guessgame.c))

### Data Structures Implemented

-   **Stack**: Reverse Polish Notation calculator ([`rpn.c`](src/rpn.c))

## 📝 Problems & Algorithms

### Sorting Algorithms

| File                                              | Algorithm      | Complexity     | Method                                  |
| ------------------------------------------------- | -------------- | -------------- | --------------------------------------- |
| [`quicksort.c`](src/quicksort.c)             | Quicksort      | O(n log n) avg | Recursive, functional style with malloc |
| [`quicksortv2.c`](src/quicksortv2.c)         | Quicksort      | O(n log n) avg | In-place, Lomuto partition              |
| [`selectionsortv2.c`](src/selectionsortv2.c) | Selection Sort | O(n²)          | In-place, minimal swaps                 |
| [`selectionsort.c`](src/selectionsort.c)     | Selection Sort | O(n²)          | Non-in-place (creates new array)        |

### Classic Problems

-   **Armstrong Numbers** ([`armstrong.c`](src/armstrong.c)) - Narcissistic number validator
-   **Collatz Conjecture** ([`collatz.c`](src/collatz.c)) - Sequence generator with step counter
-   **Hamming Distance** ([`hamming.c`](src/hamming.c)) - String difference calculator (DNA sequences)
-   **Magic Square** ([`magicsquare.c`](src/magicsquare.c)) - Odd-order magic square generator using Siamese method
-   **Happy Numbers** ([`happynum.c`](src/happynum.c)) - Detects if number reaches 1 in sum-of-squares sequence
-   **Random Walk** ([`wanderer.c`](src/wanderer.c)) - 10×10 grid path generator (A-Z) with backtracking

### Data Structures

-   **Stack** ([`rpn.c`](src/rpn.c)) - RPN calculator with push/pop operations

### Practical Applications

-   **Readability Grader** ([`readability.c`](src/readability.c)) - Coleman-Liau index implementation
-   **Flight Scheduler** ([`departure.c`](src/departure.c)) - Closest departure time finder
-   **Number Converter** ([`numconv.c`](src/numconv.c)) - Decimal to binary (integer + fractional)

### Puzzles & Games

-   **Chess Queen Attack** ([`chesspos.c`](src/chesspos.c)) - Determine if queens can attack each other, more on this in the N-queens problem someday.
-   **Guessing Game** ([`guessgame.c`](src/guessgame.c)) - Program guesses number using binary search
-   **Sudoku Solver** ([`sudoku.c`](src/sudoku.c)) - Backtracking-based Sudoku puzzle solver

## 🛠️ Development

### Code Formatting

```bash
# Format all files according to .clang-format
clang-format -i *.c src/*.c include/*.h
```

### Adding New Problems

1. Create `src/yourproblem.c`
2. Include necessary headers from [`include/`](include/)
3. Add `main()` function for standalone execution
4. Update this README with problem description

### Style Guidelines

-   4-space indentation (no tabs)
-   K&R brace style for control structures
-   Left-aligned pointers: `int* ptr`
-   Use [`utils.h`](include/utils.h) for common utilities (e.g., `readline()`)

## 📋 Problem Lists

Additional challenging problems are documented in:

-   [`intermediate_problems.md`](intermediate_problems.md) - Intermediate problems (maze generation, linked lists, etc.)
-   [`advanced_problems.md`](advanced_problems.md) - Advanced problems (N-Queens, Huffman coding, etc.)

## 📄 License

This project is released into the public domain under the [Unlicense](UNLICENSE).
