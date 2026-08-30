## Summary

This program solves the **0/1 Knapsack Problem** using the **Dynamic Programming** method. The user enters the number of items, their weights, values, and the maximum capacity of the knapsack. The program then uses a DP table to find the best combination of items that gives the maximum value without exceeding the given capacity.

For each item, the program checks whether it is better to include the item or leave it out. It stores the results of previous calculations in the DP table so that they can be reused instead of calculating them again. I have also used the `chrono` library to calculate the execution time of the program.

The **time complexity** of this approach is **O(n × capacity)** and the **space complexity** is **O(n × capacity)**.

## Conclusion

In this practical, I implemented the **0/1 Knapsack Problem using Dynamic Programming**. The program successfully finds the maximum value that can be obtained within the given capacity.

By working on this program, I understood how Dynamic Programming can be used to solve problems by breaking them into smaller parts and storing their results for future use. I also learned how to calculate the time and space complexity of an algorithm and measure its actual execution time using C++.

Overall, this practical helped me understand the **Knapsack Problem, Dynamic Programming, optimization, and algorithm complexity** in a practical way.
