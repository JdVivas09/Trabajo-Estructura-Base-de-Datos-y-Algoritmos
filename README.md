# Trabajo-Estructura-Base-de-Datos-y-Algoritmos

---

# Sorting Algorithms Implementation & Analysis

## Implementation Approach

### Quicksort

Quicksort was implemented using a dynamic array (`std::vector<string>`) as indicated in the practice instructions. The algorithm follows a **divide-and-conquer** approach, selecting a pivot element and partitioning the dataset into two arrays:

* Elements smaller than the pivot
* Elements greater than the pivot

The partitioning process rearranges elements **in-place** using string comparisons. Since C++ supports lexicographical comparison (`<`, `<=`), the dataset is sorted alphabetically based on ASCII values, without needing manual indexing.

After partitioning, Quicksort is recursively applied to both subarrays until the dataset is fully sorted.

---

### Heapsort

Heapsort was implemented using a **dynamic array representation** instead of a node-based structure, since a Binary Heap is a **complete binary tree** and can be efficiently stored in an array.

Each index follows:

* Left child → `2i + 1`
* Right child → `2i + 2`

The heap construction starts at index `n/2 − 1` because nodes from `n/2` to `n − 1` are leaf nodes and already satisfy heap properties.

A **max-heap** was used to ensure the largest element is always at the root. During sorting:

1. The root is swapped with the last element
2. Heap size is reduced
3. Heap property is restored (heapify)

This process repeats until the array is fully sorted.

---

### AVL Tree Sorting

The AVL Tree was implemented as a **self-balancing binary search tree** using a node-based structure.

Each node contains:

* A string value
* Left and right pointers
* Height

Balance is maintained using the **balance factor** (difference between left and right subtree heights). When imbalance occurs, rotations are applied:

* Left
* Right
* Left-Right
* Right-Left

After inserting all elements, an **inorder traversal** (left → root → right) is performed, returning the dataset in alphabetical order.

---

## Comparative Analysis

### Experimental Results

After running each algorithm five times:

| Algorithm     | Avg Time (s) | Memory Usage (bytes) |
| ------------- | ------------ | -------------------- |
| Quicksort     | 0.128018     | 6,143,783            |
| Heapsort      | 0.175602     | 6,143,783            |
| AVL Tree Sort | 0.210189     | 6,432,638            |

---

### Time Complexity

| Algorithm     | Average Case | Worst Case |
| ------------- | ------------ | ---------- |
| Quicksort     | O(n log n)   | O(n²)      |
| Heapsort      | O(n log n)   | O(n log n) |
| AVL Tree Sort | O(n log n)   | O(n log n) |

Differences between theoretical and practical performance arise due to:

* Memory access patterns
* Cache efficiency
* Constant factors (not reflected in Big-O notation)

---

### Advantages & Disadvantages

#### Quicksort & Heapsort

**Advantages:**

* Efficient memory usage (contiguous memory)
* Fast read/write operations

**Disadvantages:**

* Inserting new data into a sorted array requires shifting elements (slow)

#### AVL Tree

**Advantages:**

* Dynamic structure (supports continuous insertions/deletions)
* Always remains sorted

**Disadvantages:**

* Higher memory usage (pointers + height storage)
* Extra overhead from balancing operations

---

## Conclusions

Among the three approaches, **Quicksort** proved to be the most efficient in practice for sorting large datasets of words. Since the dataset is randomized, it avoids the worst-case scenario and achieves the fastest execution time.

**Heapsort** provides a reliable alternative with guaranteed `O(n log n)` performance, but is slightly slower in practice.

The **AVL Tree approach**, while theoretically efficient, is less practical for this specific problem due to:

* Higher memory consumption
* Additional balancing overhead

---

## References

* AVL tree data structure. (2023, January 2). *GeeksforGeeks*.
  [https://www.geeksforgeeks.org/dsa/introduction-to-avl-tree/](https://www.geeksforgeeks.org/dsa/introduction-to-avl-tree/)

* Binary heap. (2014, November 1). *GeeksforGeeks*.
  [https://www.geeksforgeeks.org/dsa/binary-heap/](https://www.geeksforgeeks.org/dsa/binary-heap/)

* Massachusetts Institute of Technology. (n.d.). *Introduction to Algorithms (Lecture 4)*. Retrieved March 22, 2026, from
  [https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-fall-2011/8ebfeb1c645b10b3709919603e7d51be_MIT6_006F11_lec04.pdf](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-fall-2011/8ebfeb1c645b10b3709919603e7d51be_MIT6_006F11_lec04.pdf)

---
