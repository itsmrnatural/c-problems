# Intermediate C Learning Problems

These are genuinely the next step up from wanderer.c and magicsquare.c. Not easy, but doable if you think through them.

---

## 1. **Random Maze Generator** (Recursive Backtracking with Structure)

**Difficulty:** Medium | **Time to solve:** 2-4 hours | **Concepts:** Backtracking, 2D grids, randomness

**Problem:**
Generate a random maze (not solve it yet, just generate). Use recursive backtracking similar to wanderer.c, but more structured.

**Requirements:**
- Start with a full grid of walls
- Carve passages using random backtracking (pick random unvisited neighbor, move there, repeat)
- Stack or recursion to backtrack when stuck
- Print the maze with walls (`#`) and passages (` `)
- Should create one connected path through the maze

**Think about:**
- How is this similar to wanderer.c? (both use backtracking + randomness)
- How is it different? (maze needs structure, not just random marks)
- How do you track which cells you've visited?

**Example Output:**
```
# # # # # # # # # #
# . . . . # . . . #
# # # . # . . # . #
# . . . . . # . . #
# . # # # # # # # #
# . . . . . . . . #
# # # # # . # # # #
```

**No extensions needed** — just get this working first.

---

## 2. **Bubble Sort Visualizer with Stats** (Sorting + Analysis)

**Difficulty:** Easy-Medium | **Time to solve:** 1-2 hours | **Concepts:** Sorting, algorithm analysis

**Problem:**
Implement bubble sort (yes, the "bad" sort) BUT add detailed analysis of what's happening.

**Requirements:**
- Implement classic bubble sort
- Count comparisons (how many times you compare two elements)
- Count swaps (how many times you swap)
- Count passes (how many times you go through array)
- Print the array after each pass
- Test with: random array, already sorted, reverse sorted
- Calculate total operations for each case

**Think about:**
- Why does bubble sort do more work on some arrays than others?
- Can you optimize it (early exit if no swaps in a pass)?
- What's the difference between best case / worst case?

**Example Output:**
```
Original: [5, 2, 8, 1, 9]

Pass 1: [2, 5, 1, 8, 9] - Comparisons: 4, Swaps: 3
Pass 2: [2, 1, 5, 8, 9] - Comparisons: 4, Swaps: 1
Pass 3: [1, 2, 5, 8, 9] - Comparisons: 4, Swaps: 1
Pass 4: [1, 2, 5, 8, 9] - Comparisons: 4, Swaps: 0

Total Comparisons: 16, Total Swaps: 5
```

---

## 3. **Perfect Number Finder** (Number Theory)

**Difficulty:** Easy-Medium | **Time to solve:** 1-2 hours | **Concepts:** Loops, divisibility, algorithms

**Problem:**
Find all perfect numbers up to a given limit. A perfect number equals the sum of its proper divisors (divisors excluding the number itself).

**Requirements:**
- Find all perfect numbers up to N (e.g., N=10000)
- For each perfect number, show its divisors
- Count how many you found
- Optimize: Don't check every number naively — think about constraints

**Think about:**
- What's a naive approach? (check every number, sum divisors)
- How can you optimize finding divisors? (hint: you only need to check up to sqrt(n))
- Are perfect numbers rare or common?

**Example Output:**
```
Perfect numbers up to 10000:
6 = 1 + 2 + 3
28 = 1 + 2 + 4 + 7 + 14
496 = 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248
8128 = ...

Total found: 4
```

---

## 4. **Pascal's Triangle Generator** (Combinatorics + 2D Arrays)

**Difficulty:** Easy-Medium | **Time to solve:** 1-2 hours | **Concepts:** 2D arrays, combinatorics

**Problem:**
Generate Pascal's triangle up to N rows. Each number is the sum of the two numbers above it.

**Requirements:**
- Generate N rows of Pascal's triangle
- Print it nicely formatted (centered or aligned)
- Store it in a 2D array
- Find/highlight specific properties (e.g., find row with sum = 2^n)

**Think about:**
- How do you represent a triangle in a 2D array?
- How do you handle the edge cases (first and last elements of each row)?
- Can you use the previous row to calculate the next row?

**Example Output (7 rows):**
```
      1
     1 1
    1 2 1
   1 3 3 1
  1 4 6 4 1
 1 5 10 10 5 1
1 6 15 20 15 6 1
```

---

## 5. **Fibonacci Sequence with Memoization** (Dynamic Programming Intro)

**Difficulty:** Medium | **Time to solve:** 2-3 hours | **Concepts:** Recursion, caching, optimization

**Problem:**
Implement Fibonacci in three ways and compare performance.

**Requirements:**
- **Version 1:** Simple recursion (slow but shows the idea)
- **Version 2:** Memoization (cache results, much faster)
- **Version 3:** Iterative (bottom-up, fastest)
- Benchmark each version: Time how long it takes to compute fib(40)
- Show how memoization helps

**Think about:**
- Why is simple recursion so slow? (recalculating same values)
- How do you store results you've already calculated?
- Why is iteration faster than recursion?

**Example Output:**
```
fib(40) = 102334155

Method 1 (Simple Recursion):  2.34 seconds
Method 2 (Memoization):       0.001 seconds
Method 3 (Iterative):         0.0001 seconds
```

---

## 6. **Prime Number Sieve** (Algorithms + Optimization)

**Difficulty:** Medium | **Time to solve:** 2-3 hours | **Concepts:** Sieves, bit manipulation, optimization

**Problem:**
Find all prime numbers up to N using the Sieve of Eratosthenes. Compare with naive primality checking.

**Requirements:**
- Implement Sieve of Eratosthenes (efficient method)
- Implement naive primality check (for comparison)
- Benchmark: Find all primes up to 1,000,000
- Count primes found
- Optional: Find twin primes (primes differing by 2, like 11 and 13)

**Think about:**
- Why is a sieve faster than checking each number individually?
- How does the algorithm work? (mark multiples as composite)
- Can you optimize space/time?

**Example Output:**
```
Primes up to 100:
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97

Total: 25 primes

Sieve time:  0.003 seconds
Naive time:  0.025 seconds
Speedup: 8.3x faster
```

---

## 7. **Word Frequency Counter** (File I/O + Data Structures)

**Difficulty:** Medium | **Time to solve:** 2-4 hours | **Concepts:** File I/O, arrays/structs, sorting

**Problem:**
Read a text file, count word frequencies, and display top N most common words.

**Requirements:**
- Read a file line by line
- Split lines into words (handle punctuation)
- Count occurrences of each word (case-insensitive)
- Sort words by frequency
- Display top 10 most common words with counts
- Ignore common words ("the", "a", "and", etc.)

**Think about:**
- How do you store words and their counts? (array of structs? dynamic array?)
- How do you convert uppercase to lowercase?
- How do you split a line into words?
- How do you remove punctuation?

**Example Output:**
```
Top 10 words in file.txt:
1. word        - 342 times
2. example     - 298 times
3. code        - 256 times
4. function    - 189 times
5. array       - 167 times
...
```

---

## 8. **Number Guessing Game with AI** (Logic + Loops)

**Difficulty:** Easy-Medium | **Time to solve:** 1-2 hours | **Concepts:** Binary search, game logic

**Problem:**
Create a guessing game where the human thinks of a number and the computer tries to guess it using binary search strategy.

**Requirements:**
- Computer generates guesses in range 1-1000
- Human responds: "higher", "lower", or "correct"
- Computer uses binary search to narrow down the number
- Count how many guesses it takes
- Validate: Detect if human is cheating (contradicting previous answers)

**Think about:**
- How does binary search narrow the search space?
- What's the maximum guesses needed for 1-1000? (log2(1000) ≈ 10)
- How do you track the search bounds?
- How do you detect cheating?

**Example Interaction:**
```
Think of a number between 1 and 1000.
My guess: 500
(higher/lower/correct) > higher
My guess: 750
(higher/lower/correct) > lower
My guess: 625
(higher/lower/correct) > higher
My guess: 687
(higher/lower/correct) > lower
My guess: 656
(higher/lower/correct) > correct
I got it in 5 guesses!
```

---

## 9. **Simple Linked List** (Dynamic Memory + Pointers)

**Difficulty:** Medium | **Time to solve:** 2-3 hours | **Concepts:** Pointers, dynamic memory, linked lists

**Problem:**
Implement a singly linked list with basic operations.

**Requirements:**
- Node structure: `value` and `next` pointer
- Operations:
  - Insert at head
  - Insert at tail
  - Delete a node by value
  - Search for a value
  - Print the list
  - Free all nodes (avoid memory leaks)
- Test each operation thoroughly

**Think about:**
- How do pointers chain together?
- What goes wrong if you don't track the head properly?
- How do you handle edge cases (empty list, single node)?
- How do you avoid memory leaks?

**Example Usage:**
```
list_insert_head(list, 5);
list_insert_head(list, 3);
list_insert_tail(list, 7);
list_print(list);           // 3 -> 5 -> 7 -> NULL
list_delete(list, 5);
list_print(list);           // 3 -> 7 -> NULL
```

---

## 10. **Matrix Operations** (2D Arrays + Math)

**Difficulty:** Medium | **Time to solve:** 2-4 hours | **Concepts:** 2D arrays, algorithms, math

**Problem:**
Implement basic matrix operations: addition, multiplication, and transpose.

**Requirements:**
- Matrix struct (rows, cols, data)
- Matrix addition: A + B = C
- Matrix multiplication: A × B = C (handle dimension validation)
- Transpose: flip rows and columns
- Print matrices nicely formatted
- Test with various dimensions

**Think about:**
- How do you validate matrix operations? (addition requires same dimensions)
- How does matrix multiplication work? (dot product of rows and columns)
- How do you handle invalid operations gracefully?

**Example Output:**
```
Matrix A (2x3):
1 2 3
4 5 6

Matrix B (2x3):
7 8 9
10 11 12

A + B:
8  10  12
14 16  18

A * B^T:
14 32
32 77

A^T (3x2):
1 4
2 5
3 6
```

---

## My Recommendation

**Pick 2-3 of these based on interest:**

**If you like logic/algorithms:**
- Fibonacci with memoization
- Prime sieve
- Number guessing game

**If you like data structures/memory:**
- Linked list
- Word frequency counter
- Pascal's triangle

**If you like getting things to work:**
- Bubble sort visualizer
- Perfect numbers
- Matrix operations

**Start with ONE. Finish it completely. Then pick another.**

Don't look anything up until you're genuinely stuck (not just confused — actually unable to progress). Struggle is where learning happens.