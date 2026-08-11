# Max Heap

Max Heap is a type of binary tree in which the **parent element is always greater than or equal to its child elements**. Because of this, the **largest element is always present at the top (root)**.

In Max Heap, elements are arranged **level by level from left to right**. While creating the heap, we compare the parent with its children and swap them when needed to maintain the Max Heap property.

For Heap Sort, we first create a Max Heap. Then we take the largest element from the top and move it to the end of the array. After that, we heapify the remaining elements and repeat the process until all elements are sorted in **ascending order**.

## Time Complexity

**O(n log n)**

## Space Complexity

**O(log n)**
