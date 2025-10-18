# C Programming Practice Repository

A collection of algorithms, data structures, and coding problems which I solved while learning C.

**Compile any program:**

```zsh
clang -Wall -Wextra -std=c99 -o program filename.c -lm
```

## 📚 Implementation

### Algorithms Implemented

-   **Divide & Conquer**: Quicksort ([`quicksort.c`](problems/quicksort.c), [`quicksortv2.c`](problems/quicksortv2.c))
-   **Comparison Sorting**: Selection Sort ([`selectionsortv2.c`](problems/selectionsortv2.c), [`selectionsort.c`](problems/selectionsort.c))
-   **Backtracking**: Random Walk ([`wanderer.c`](problems/wanderer.c)), Sudoku Solver ([`sudoku.c`](problems/sudoku.c))
-   **Iteration & Recursion**: 
    - Hamming Distance ([`hamming.c`](problems/hamming.c))
    - Number Conversion ([`numconv.c`](problems/numconv.c))
    - Collatz Conjecture ([`collatz.c`](problems/collatz.c))
    - Armstrong Numbers ([`armstrong.c`](problems/armstrong.c))
    - Happy Numbers ([`happynum.c`](problems/happynum.c))
-   **Mathematical Algorithms**: Magic Square - Siamese Method ([`magicsquare.c`](problems/magicsquare.c))
-   **Stack-Based**: RPN Calculator ([`rpn.c`](problems/rpn.c))
-   **String Processing**: Readability grading - Coleman-Liau Index ([`readability.c`](problems/readability.c))
-   **Search Algorithms**: Binary search in guessing game ([`guessgame.c`](problems/guessgame.c))

### Data Structures Implemented

-   **Stack**: Reverse Polish Notation calculator ([`rpn.c`](problems/rpn.c))

## 📝 Problems & Algorithms

### Sorting Algorithms

| File                                | Algorithm      | Complexity     | Method                                  |
| ----------------------------------- | -------------- | -------------- | --------------------------------------- |
| [`quicksort.c`](problems/quicksort.c)       | Quicksort      | O(n log n) avg | Recursive, functional style with malloc |
| [`quicksortv2.c`](problems/quicksortv2.c)     | Quicksort      | O(n log n) avg | In-place, Lomuto partition              |
| [`selectionsortv2.c`](problems/selectionsortv2.c) | Selection Sort | O(n²)          | In-place, minimal swaps                 |
| [`selectionsort.c`](problems/selectionsort.c)   | Selection Sort | O(n²)          | Non-in-place (creates new array)        |

### Classic Problems

-   **Armstrong Numbers** ([`armstrong.c`](problems/armstrong.c)) - Narcissistic number validator
-   **Collatz Conjecture** ([`collatz.c`](problems/collatz.c)) - Sequence generator with step counter
-   **Hamming Distance** ([`hamming.c`](problems/hamming.c)) - String difference calculator (DNA sequences)
-   **Magic Square** ([`magicsquare.c`](problems/magicsquare.c)) - Odd-order magic square generator using Siamese method
-   **Happy Numbers** ([`happynum.c`](problems/happynum.c)) - Detects if number reaches 1 in sum-of-squares sequence
-   **Random Walk** ([`wanderer.c`](problems/wanderer.c)) - 10×10 grid path generator (A-Z) with backtracking

### Data Structures

-   **Stack** ([`rpn.c`](problems/rpn.c)) - RPN calculator with push/pop operations

### Practical Applications

-   **Readability Grader** ([`readability.c`](problems/readability.c)) - Coleman-Liau index implementation
-   **Flight Scheduler** ([`departure.c`](problems/departure.c)) - Closest departure time finder
-   **Number Converter** ([`numconv.c`](problems/numconv.c)) - Decimal to binary (integer + fractional)

### Puzzles & Games

-   **Chess Queen Attack** ([`chesspos.c`](problems/chesspos.c)) - Determine if queens can attack each other, more on this in the N-queens problem someday.
-   **Guessing Game** ([`guessgame.c`](problems/guessgame.c)) - Program guesses number using binary search
-   **Sudoku Solver** ([`sudoku.c`](problems/sudoku.c)) - Backtracking-based Sudoku puzzle solver

## 🛠️ Development

### Code Formatting

```bash
# Format all files according to .clang-format
clang-format -i *.c problems/*.c include/*.h
```

### Adding New Problems

1. Create `problems/yourproblem.c`
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