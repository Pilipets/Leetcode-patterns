
## Algo questions or leetcode problem patterns

#LeetCode #Patterns #LeetcodePatterns #DataStructures

### Preparation links:
- [Cheetsheets](https://leetcode.com/explore/interview/card/cheatsheets/)
- [Top Interview Questions](https://leetcode.com/explore/interview/card/top-interview-questions-medium/)
- [Materials used](https://github.com/Pilipets/CsMaterials)
- [LC how to score 2200+](https://leetcode.com/discuss/study-guide/1965086/How-to-practice-for-2200%2B-rating-in-LC)

### Pattern Links:
- https://designgurus.org/blog/grokking-leetcode;
- https://designgurus.org/blog/top-lc-patterns;
- https://seanprashad.com/leetcode-patterns;

### Best problem patterns:
- Binary Search(Arrays) - binary search the answer and see if it works, binary search the prefix sum to find longest sub in an array;
- Sliding Window(Arrays, Strings, Hash Tables) - input data in a specific window size, increase the size while condition is met, move the start after;
- BFS/DFS - subsets, queue, topological sort, tree/graph/matrix traversal;
- Two Pointers, Fast & Slow Pointer(Arrays, Strings) - move opposite direction at a constant interval, traverse input data on different speeds;
- Union Find or Disjoint Set Data-structure;
- Recursion/Memoization/Backtracking;
- Dynamic Programming;
- Graphs(shortest path, minimum spanning tree, A*)
- Sorting(HeapSort, Bucket Sort, QuickSelect, QuickSort);
- Greedy;

### Best Data Structures:
- Hash Table;
- Prefix sum;
- Heap(Priority Queue, Binary);
- Trie(Prefix Tree, Strings Tree);
- DSU(Disjoint Set Data-structure);
- Tree(Binary, AVL, Red-Black, Statistic Order);
- Stack/Queue;
- Deque;
- Segment Tree(Fenwick Tree or Binary Indexed Tree/BIT);

### Extended problem patterns:
- Monotonic Stack;
- Islands(Matrix, Queue) - flood fill, efficient way of traversing traversing a matrix or 2d array;
- Merge intervals(Arrays, Heap) - deal with overlapping intervals;
- Topological Sort (Array, HashTable, Queue, Graph) - linear ordering of elements that have dependencies on each other;
- Top K elements(Array, Heap, Queue) - find top/smallest/frequently occurring K elements in a set;
- Two Heaps(Heap, Array) - set of elements can be divided into two parts, smallest element in one part(Min-Heap) and biggest in the other part(Max-Heap);
- Cyclic Sort(Arrays) - input data lies within a fixed range;
- 0/1 Knapsack(Array, HashTable) - dynamic programming to solve optimization problems, given a set of items(weight + value), determine the number of each item to include in a collection so that the total weight <= limit and the total value is as large as possible;
- Subsets(Queue, Array, String) - deal with permutations or combinations of a set of elements;
- Fibonacci Numbers(Array, HashTable) - every subsequent number is calculated from the last few numbers;
- Palindromic Subsequence(Array, HashTable) - dynamic programming on lps(longest palindromic  1, 2) solve optimization problems related to palindromic sequences or strings;
- Longest Common Substring(Array, HashTable) - optimal is dynamic programming(1) or less efficient binsearch the length + hashtable with rolling hash(2);
- K-way merge(Array, Queue, Heap) - solve problems that involve a list of sorted arrays;
- Math (sieve, log);
- Bitwise XOR(Array, Bits) - manipulate bits to solve problems, a ^ a = 0;
- Eulerian Path - build a path problems(domino, etc) converted into graphs where every edge/vertex must be used once.

### Almost never used data-structures, but fancy:
- Treap, Rope, Cartesian Tree;
- Splay Tree, B Tree, B+ Tree, K-D tree;
- Heap(Binomial, Fibonacci);
- Skip List;
- Suffix Array/Suffix Tree;
