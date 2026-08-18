## 📌 Summary

This project solves the **Coin Change Problem** using the **Dynamic Programming** approach. The main goal is to find the minimum number of coins needed to make a given amount using the available coin denominations.

The program uses a DP array to store the minimum number of coins required for each amount from `0` to the given amount. It starts with `dp[0] = 0` and builds the solution step by step using the available coins.

The program also measures the execution time using C++'s `chrono` library.

### Key Points
- Uses **Dynamic Programming** to solve the Coin Change Problem.
- Finds the **minimum number of coins** required.
- Handles cases where the amount cannot be formed.
- Measures execution time in **nanoseconds**.
- **Time Complexity:** `O(n × amount)`
- **Space Complexity:** `O(amount)`

## Conclusion

This project shows how **Dynamic Programming** can make a problem more efficient by storing previously calculated results and reusing them instead of calculating the same values again.

The solution is simple and efficient for finding the minimum number of coins. It also gives a practical understanding of **Dynamic Programming, time complexity, space complexity, and execution-time analysis**.
