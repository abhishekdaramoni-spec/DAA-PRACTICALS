# Practical-2: Searching Algorithms in C++

## Summary

In this practical, I implemented and analyzed two searching algorithms in C++: **Linear Search** and **Binary Search**. Each program accepts an array of integers from the user, searches for a given element, displays whether the element is found along with its index, measures the execution time using the C++ `<chrono>` library, and reports the corresponding time and space complexities.

Through this implementation, I observed the working principles of each algorithm:

- **Linear Search** checks each element one by one until the required element is found or the entire array has been searched. It works on both sorted and unsorted arrays.
- **Binary Search** follows the divide-and-conquer approach by repeatedly dividing the sorted array into two halves and comparing the middle element with the target value. It works only on sorted arrays and is much faster than Linear Search for large datasets.

The execution time recorded for each algorithm provided a practical comparison of their efficiency, while the theoretical time and space complexities helped explain their performance for different input sizes.

## Conclusion

This practical helped me understand the working of different searching algorithms and their efficiency. By implementing Linear Search and Binary Search, I learned that Linear Search is simple and can be used for any array, while Binary Search is more efficient but requires the array to be sorted. Comparing their execution time, time complexity, and space complexity helped me understand when each searching algorithm should be used. Overall, this practical improved my understanding of searching techniques and their real-world applications.
