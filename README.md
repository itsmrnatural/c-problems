# C Programming Practice Repository

A collection of algorithms, data structures, and coding problems which I solved while learning C.

**Compile any program:**

```zsh
clang -Wall -Wextra -std=c99 -o program filename.c -lm
```

## 📚 Implementation

### Algorithms Implemented

-   **Divide & Conquer**: Quicksort
-   **Backtracking**: Random Walk (Wanderer)

### Datastructures Implemented

-   **Stack**: Reverse Polish Notation calculator (`rpn.c`)

## 📝 Problems & Algorithms

### Sorting Algorithms

| File                | Algorithm      | Complexity     | Method                                  |
| ------------------- | -------------- | -------------- | --------------------------------------- |
| `quicksort.c`       | Quicksort      | O(n log n) avg | Recursive, functional style with malloc |
| `quicksortv2.c`     | Quicksort      | O(n log n) avg | In-place, Lomuto partition              |
| `selectionsortv2.c` | Selection Sort | O(n²)          | In-place, minimal swaps                 |

### Classic Problems

-   **Armstrong Numbers** (`armstrong.c`) - Narcissistic number validator
-   **Collatz Conjecture** (`collatz.c`) - Sequence generator with step counter
-   **Hamming Distance** (`hamming.c`, `hammingv2.c`) - String difference calculator
-   **Magic Square** (`magicsquare.c`) - Odd-order magic square generator using Siamese method
-   **Happy Numbers** (`happynum.c`) - Detects if number reaches 1 in sum-of-squares sequence
-   **Random Walk** (`wanderer.c`) - 10×10 grid path generator (A-Z)

### Data Structures

-   **Stack** (`rpn.c`) - RPN calculator with stack operations

### Practical Applications

-   **Readability Grader** (`readability.c`) - Coleman-Liau index implementation
-   **Flight Scheduler** (`departure.c`) - Closest departure time finder
-   **Number Converter** (`numconv.c`) - Decimal to binary (integer + fractional)

### Puzzles & Games

-   **Chess Queen Attack** (`chesspos.c`) - Determine if queens can attack each other
-   **Resistor Colors** (`resistors.c`) - Decode resistor band value

## 🛠️ Development

### Code Formatting

```bash
# Format all files according to .clang-format
clang-format -i *.c problems/*.c include/*.h
```

### Adding New Problems

1. Create `problems/yourproblem.c`
2. Include necessary headers
3. Add `main()` function for standalone execution
4. Update this README with problem description

### Style Guidelines

-   4-space indentation (no tabs)
-   K&R brace style for control structures
-   Left-aligned pointers: `int* ptr`
