Max Heap 

A Max Heap is a type of binary tree where the parent element is always greater than its child elements. Because of this, the largest element is always present at the top (root).

In Max Heap, elements are arranged level by level from left to right. When we add or remove an element, we compare it with its parent or children and swap the elements if necessary to maintain the Max Heap property.

For Heap Sort, we first create a Max Heap. Then we take the largest element from the top and move it to the end of the array. After that, we heapify the remaining elements and repeat the same process until the complete array is sorted in ascending order.

The time complexity of Heap Sort is O(n log n), and the space complexity is O(log n) when recursive heapify is used.
