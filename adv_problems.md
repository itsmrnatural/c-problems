# Advanced C Learning Problems

Pick problems that interest you. They're ordered roughly by difficulty, but jump around based on what excites you.

> **Legend:** ✅ Done | 🔄 In Progress | 📋 To Do

---

## 1. ✅ **N-Queens Solver** (Backtracking + Optimization)

**Difficulty:** Medium-Hard | **Concepts:** Backtracking, constraint satisfaction

**Problem:**
Implement a solver for the N-Queens problem. Given an integer `n`, place `n` chess queens on an `n×n` chessboard such that no two queens can attack each other (no two queens on same row, column, or diagonal).

**Requirements:**

- Find ALL valid solutions
- Print each solution as a grid (use `Q` for queen, `.` for empty)
- Count total solutions
- Optimize: Don't place queens in rows/columns/diagonals that already have queens

**Extension (Hard):**

- Benchmark: How fast can you solve n=10, n=12?
- Implement bit manipulation optimization (use bitmasks for row/column/diagonal tracking)

**Example Output (4-Queens, 1 solution):**

```
. Q . .
. . . Q
Q . . .
. . Q .
```

---

## 2. ✅ **Sudoku Solver** (Backtracking with Constraints)

**Difficulty:** Medium-Hard | **Concepts:** Backtracking, constraint propagation, data structures

**Problem:**
Implement a Sudoku solver. Read a partially-filled 9×9 Sudoku grid and find the unique solution using backtracking.

**Requirements:**

- Represent the board (9×9 grid)
- Track which numbers are possible in each cell
- Implement backtracking with constraint checking
- Print the solved board
- Optimize: Use "naked singles" (cells with only one possibility)

**Input Format:**

```
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
```

(Use 0 or `.` for empty cells)

**Extension (Hard):**

- Count how many solutions exist (some puzzles have multiple solutions)
- Implement "constraint propagation" for faster solving

---

## 3. 📋 **Graph Pathfinding: Maze Solver** (Graph Algorithms)

**Difficulty:** Medium | **Concepts:** BFS/DFS, graph traversal, dynamic memory

**Problem:**
Generate and solve mazes. Create an algorithm that:

1. Generates a random maze using recursive backtracking (similar to wanderer, but more structured)
2. Solves it using BFS to find the shortest path from start to end

**Requirements:**

- Represent maze as 2D grid (walls and passages)
- Implement DFS-based maze generation (Recursive Backtracking)
- Implement BFS to find shortest path
- Visualize: Print maze with path marked as `*` or different character
- Track path length and steps explored

**Visual Example:**

```
# # # # # # # # #
# S . . # . . . #
# # # . # . # . #
# . . . . . # . #
# . # # # # # . #
# . . . . . . . E
# # # # # # # # #
```

**Extension (Hard):**

- Implement A* pathfinding (heuristic-based, faster than BFS for large mazes)
- Generate multiple maze styles (recursive backtracking vs Prim's algorithm)

---

## 4. ✅ **Binary Search Tree with Balancing** (Data Structures)

**Difficulty:** Hard | **Concepts:** Dynamic memory, tree traversal, self-balancing

**Problem:**
Implement a Binary Search Tree (BST) with AVL tree balancing. Support insertions/deletions while maintaining O(log n) height.

**Requirements:**

- Node structure with left/right children and height
- Insert: Add values, rebalance if needed
- Delete: Remove values, rebalance
- Traversals: In-order, Pre-order, Post-order, Level-order
- Detect imbalance: Calculate balance factor
- Rotations: Implement left/right rotations for rebalancing
- Visualize: Print tree structure (ASCII art)

**Example Operations:**

```c
tree_insert(root, 10);
tree_insert(root, 5);
tree_insert(root, 15);
tree_insert(root, 3);
tree_print_inorder(root);  // Output: 3 5 10 15
tree_print_tree(root);     // Pretty-print tree structure
tree_delete(root, 5);
```

**Extension (Hard):**

- Implement Red-Black Tree instead (different balancing strategy)
- Add range queries (find all values between X and Y)

---

## 5. 📋 **Huffman Coding** (Greedy + Data Structures)

**Difficulty:** Hard | **Concepts:** Greedy algorithms, priority queues (heaps), file I/O

**Problem:**
Implement Huffman coding to compress and decompress text files.

**Requirements:**

- Analyze text: Count character frequencies
- Build Huffman tree using a priority queue (min-heap)
- Generate codes: Assign binary codes to each character
- Encode: Convert text to binary using codes
- Decode: Reconstruct original text from binary + tree
- File I/O: Read input file, write compressed/decompressed output

**Algorithm Outline:**

1. Count frequencies of all characters
2. Create leaf nodes for each character
3. Build tree bottom-up: Always combine two smallest-frequency nodes
4. Traverse tree to assign codes (left=0, right=1)
5. Encode text using codes, store tree for decompression

**Example:**

```
Input: "hello world"
Character frequencies: h:1, e:1, l:3, o:2, ' ':1, w:1, r:1, d:1

Huffman codes (example):
l: 0
o: 10
e: 110
h: 1110
...

Compressed size: Much smaller than original
```

**Extension (Hard):**

- Implement adaptive Huffman coding (tree updates as you decode)
- Add RLE (Run-Length Encoding) preprocessing

---

## 6. 📋 **Topological Sort + Dependency Resolver** (Graph Algorithms)

**Difficulty:** Medium-Hard | **Concepts:** Graph representation, cycle detection, DFS

**Problem:**
Implement a build system dependency resolver. Given a set of tasks with dependencies, determine the correct build order.

**Requirements:**

- Represent tasks and dependencies as a directed graph
- Detect cycles (circular dependencies) — return error if found
- Implement Kahn's algorithm or DFS-based topological sort
- Output valid build order
- Validate: Ensure all dependencies are satisfied in output

**Input Format:**

```
task_a: []
task_b: [task_a]
task_c: [task_a, task_b]
task_d: [task_c]
```

**Output:**

```
Build order: task_a -> task_b -> task_c -> task_d
```

**Extension (Hard):**

- Parallel execution: Identify tasks that can run simultaneously
- Critical path: Find the longest dependency chain

---

## 7. 📋 **Rabin-Karp String Matching** (String Algorithms + Hashing)

**Difficulty:** Medium | **Concepts:** Hashing, rolling hash, pattern matching

**Problem:**
Implement Rabin-Karp algorithm to find all occurrences of a pattern in a text using rolling hash.

**Requirements:**

- Implement rolling hash function
- Search for pattern in text (return all positions)
- Handle hash collisions (verify matches)
- Optimize: Avoid unnecessary character-by-character comparisons
- Benchmark: Compare against naive string matching

**Algorithm Outline:**

1. Compute hash of pattern
2. Compute hash of first window of text
3. Slide window: Update hash in O(1) time (rolling hash)
4. When hashes match, verify actual match (avoid false positives)
5. Report all matches

**Example:**

```
Text: "ABCCCCCDDEF"
Pattern: "CCC"

Matches found at positions: 2, 3, 4
```

**Extension (Hard):**

- Handle multiple pattern matching (search for many patterns simultaneously)
- Implement with polynomial rolling hash to reduce collisions

---

## 8. ✅ **Mergesort with Inversion Counter** (Divide & Conquer + Analysis)

> *Note: Mergesort is implemented in `mergesort.c`, but inversion counting is not yet added.*

**Difficulty:** Medium | **Concepts:** Merge sort, counting inversions, analysis

**Problem:**
Implement mergesort AND count inversions in an array. An inversion is a pair (i, j) where i < j but arr[i] > arr[j].

**Requirements:**

- Implement mergesort (you've done quicksort, this is different)
- Count inversions during merge step
- Return both sorted array AND inversion count
- Time complexity: O(n log n)
- Optimize: Don't count inversions naively — do it efficiently during merging

**Example:**

```
Input: [3, 1, 2]
Inversions: (3,1), (3,2) = 2 inversions
Output: sorted = [1, 2, 3], inversions = 2
```

**Extension (Hard):**

- Use this to detect how "sorted" an array is
- Implement external sorting (for arrays larger than RAM)

---

## 9. 📋 **LRU Cache** (Data Structures + Hash Maps)

**Difficulty:** Hard | **Concepts:** Hash tables, doubly-linked lists, cache design

**Problem:**
Implement an LRU (Least Recently Used) cache with fixed capacity.

**Requirements:**

- Initialize cache with max capacity
- `get(key)`: O(1) lookup, marks as recently used
- `put(key, value)`: O(1) insertion, evicts LRU item if full
- All operations must be O(1)
- Use combination of hash table (for O(1) lookup) + doubly-linked list (for LRU ordering)

**Example:**

```
cache = LRU_Cache(2);
put(1, 1);          // cache: {1=1}
put(2, 2);          // cache: {1=1, 2=2}
get(1);             // returns 1, cache: {2=2, 1=1}
put(3, 3);          // evicts 2, cache: {1=1, 3=3}
get(2);             // returns -1 (not found)
```

**Data Structure Trick:**

- Hash table: `key -> node_pointer`
- Doubly-linked list: Most recently used at head, LRU at tail
- When accessed: Move node to head
- When full: Remove tail node

**Extension (Hard):**

- Implement LFU (Least Frequently Used) cache
- Add expiration times (TTL) for entries

---

## 10. 📋 **Expression Parser & Evaluator** (Parsing + Recursion)

**Difficulty:** Hard | **Concepts:** Parsing, recursion, operator precedence

**Problem:**
Build a mathematical expression parser that handles operator precedence and parentheses.

**Requirements:**

- Parse expressions: `3 + 4 * 2 - (5 - 2)`
- Respect operator precedence: `*` and `/` before `+` and `-`
- Handle parentheses
- Implement recursive descent parser OR shunting-yard algorithm
- Return result of evaluation

**Example:**

```
Input: "3 + 4 * 2"
Output: 11 (not 14, because * has higher precedence)

Input: "(3 + 4) * 2"
Output: 14
```

**Parsing Approaches:**

- **Recursive Descent:** Write recursive functions for each precedence level
- **Shunting Yard:** Convert infix to postfix, evaluate (you've done RPN!)

**Extension (Hard):**

- Support functions: `sin(x)`, `max(a, b)`
- Variables: `2*x + 3*y` (substitute values)
- Scientific notation: `1e-5`, `3.14e2`

---

## 11. 📋 **Aho-Corasick String Matching** (Advanced String Algorithms)

**Difficulty:** Hard | **Concepts:** Trie, finite automata, multiple pattern matching

**Problem:**
Implement Aho-Corasick algorithm for multi-pattern string matching. Search for multiple patterns in a text simultaneously in linear time.

**Requirements:**

- Build a trie of all search patterns
- Add failure links (like KMP failure function, but for tries)
- Add output links (for overlapping matches)
- Search text in O(n + m + z) time where n=text length, m=total pattern length, z=matches
- Handle overlapping patterns correctly
- Report all matches with positions

**Algorithm Overview:**

1. Build trie of all patterns (goto function)
2. Compute failure function (suffix links for mismatch handling)
3. Compute output function (which patterns end at each node)
4. Search: Follow transitions, using failure links when necessary

**Example:**

```
Patterns: ["he", "she", "his", "hers"]
Text: "she sells seashells"

Matches:
- "she" at position 0
- "he" at position 1 (overlapping with "she")
- "she" at position 14
- "he" at position 15
```

**Why This Is Cool:**

Used in: virus scanners, intrusion detection systems, text editors (find/replace multiple terms), bioinformatics. Way faster than running multiple searches!

**Extension (Hard):**

- Wildcard patterns (support `.` as any character)
- Case-insensitive matching
- DNA sequence matching with mismatches allowed

---

## 12. 📋 **Bloom Filter with Counting** (Advanced Probabilistic DS)

**Difficulty:** Medium-Hard | **Concepts:** Hashing, probabilistic data structures, deletion support

**Problem:**
Extend a basic Bloom filter to support deletion by using counters instead of bits. This is a Counting Bloom Filter.

**Requirements:**

- Use array of counters (4-bit each) instead of single bits
- `cbf_add(filter, item)`: Increment K counters
- `cbf_remove(filter, item)`: Decrement K counters (if not zero)
- `cbf_check(filter, item)`: Check if all K counters > 0
- Handle counter overflow (cap at max value)
- Calculate false positive rate

**Challenges:**

- Space: Using 4 bits per counter uses 4x more memory than basic bloom filter
- Overflow: What happens when counter reaches max (15 for 4-bit)?
- False negatives: Can occur if you remove items that hash to same positions

**Example Output:**

```
Counting Bloom Filter: 1024 counters (4 bits each), 4 hash functions

Adding: cat, dog, car
Counters at positions [45, 89, 234, 567] = [1, 1, 1, 1]

Removing: dog
Counters updated

Check "cat" -> POSSIBLY IN SET ✓
Check "dog" -> DEFINITELY NOT IN SET ✓
```

**Extension (Hard):**

- Implement d-left counting bloom filter (better distribution)
- Add automatic resizing when false positive rate gets too high
- Use variable-width counters (start with 1-bit, expand as needed)

---

## 13. 📋 **A* Pathfinding** (Graph Algorithms + Heuristics)

**Difficulty:** Hard | **Concepts:** Priority queues (heaps), graph search, heuristics

**Problem:**
Implement A* (A-star) pathfinding algorithm. Like Dijkstra's but uses a heuristic to find paths faster.

**Requirements:**

- Represent grid as graph (8-directional movement)
- Implement min-heap (priority queue)
- Cost function: `f(n) = g(n) + h(n)` where:
  - `g(n)` = actual cost from start to n
  - `h(n)` = heuristic estimate from n to goal
- Use Manhattan or Euclidean distance as heuristic
- Reconstruct path from start to goal
- Compare A* vs Dijkstra vs BFS (show nodes explored)

**Example:**

```
Grid (# = obstacle, S = start, G = goal):
. . . # . . . .
. # . # . . . .
. # . . . # # .
. . . # . . . G
S . . # . . . .

A* Path (marked with *):
* * * # . . . .
. # * # . . . .
. # * * * # # .
. . . # * * * G
S . . # . . . .

Nodes explored: 18 (vs 45 for Dijkstra, vs 62 for BFS)
```

**Heuristic Ideas:**

- Manhattan distance: `|x1-x2| + |y1-y2|` (4-directional)
- Euclidean distance: `sqrt((x1-x2)² + (y1-y2)²)` (any direction)
- Chebyshev distance: `max(|x1-x2|, |y1-y2|)` (8-directional)

**Extension (Hard):**

- Weighted terrain (grass = 1, water = 3, mountain = 5)
- Bidirectional A* (search from both start and goal)
- Jump Point Search (optimization for uniform-cost grids)

---

## 14. 📋 **Disjoint Set Union (Union-Find)** (Data Structures + Path Compression)

**Difficulty:** Medium-Hard | **Concepts:** Disjoint sets, path compression, union by rank

**Problem:**
Implement Union-Find (Disjoint Set Union) with path compression and union by rank optimizations. Essential for graph algorithms like Kruskal's MST.

**Requirements:**

- Initialize N disjoint sets (each element in own set)
- `find(x)`: Return representative (root) of set containing x
- `union(x, y)`: Merge sets containing x and y
- Path compression: Flatten tree during find (amortized O(α(n)) ≈ O(1))
- Union by rank: Always attach smaller tree under larger tree
- `connected(x, y)`: Check if x and y in same set

**Example Usage:**

```
Initialize 10 elements (0-9):
Each element is in its own set: {0}, {1}, {2}, ..., {9}

union(0, 1)  → Sets: {0,1}, {2}, {3}, ...
union(2, 3)  → Sets: {0,1}, {2,3}, {4}, ...
union(0, 2)  → Sets: {0,1,2,3}, {4}, {5}, ...

find(1) → 0 (representative of {0,1,2,3})
find(3) → 0 (same set)
connected(1, 3) → true
connected(1, 5) → false
```

**Applications:**

- Detect cycles in undirected graphs
- Kruskal's minimum spanning tree algorithm
- Image segmentation (group connected pixels)
- Network connectivity

**Extension (Hard):**

- Implement Kruskal's MST using Union-Find
- Add `size(x)`: Return size of set containing x
- Online connectivity queries (process queries in real-time)

---

## Recommended Progression

**Start here (get comfortable):**

1. N-Queens
2. Maze Solver (BFS/DFS)
3. Mergesort with Inversion Counter

**Then level up (build real skills):**
4. Binary Search Tree with Balancing
5. Sudoku Solver
6. Rabin-Karp String Matching
7. **Disjoint Set Union** ← New! Foundation for graph algorithms

**Then go deep (hard problems):**
8. Huffman Coding
9. LRU Cache
10. Expression Parser
11. Topological Sort
12. **A* Pathfinding** ← New! Optimal pathfinding with heuristics
13. **Aho-Corasick** ← New! Multi-pattern string matching
14. **Counting Bloom Filter** ← New! Advanced probabilistic DS

---

## Implementation Tips

**For all of these:**

- Start with pseudocode first
- Test with small examples before scaling up
- Use `assert()` to verify invariants
- Memory management: Use `valgrind` to check for leaks
- Benchmark: Time your solutions on large inputs
- Write helper functions to visualize/debug

**Common pitfalls:**

- Off-by-one errors in array indexing
- Not freeing dynamically allocated memory
- Not handling edge cases (empty input, single element, etc.)
- Forgetting to initialize pointers to NULL

Good luck! Pick the one that excites you most.
