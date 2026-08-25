#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int knapsack(vector<int> &weight, vector<int> &value,
             int n, int capacity)
{
    // Create DP table
    vector<vector<int>> dp(n + 1,
                           vector<int>(capacity + 1, 0));

    // Bottom-Up Dynamic Programming
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            // If current item fits
            if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    dp[i - 1][w], // Don't take item

                    value[i - 1] +
                        dp[i - 1][w - weight[i - 1]]
                    // Take item
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    int n, capacity;

    // Input number of items
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n);
    vector<int> value(n);

    // Input weights
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    // Input values
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    // Input maximum capacity
    cout << "Enter maximum capacity: ";
    cin >> capacity;

    // Start execution time
    auto start = chrono::high_resolution_clock::now();

    int result = knapsack(weight, value, n, capacity);

    // End execution time
    auto end = chrono::high_resolution_clock::now();

    // Calculate execution time
    auto executionTime =
        chrono::duration_cast<chrono::nanoseconds>(end - start);

    // Output result
    cout << "\nMaximum Value = " << result << endl;

    cout << "Execution Time = "
         << executionTime.count()
         << " nanoseconds" << endl;

    cout << "Time Complexity = O(n * capacity)" << endl;
    cout << "Space Complexity = O(n * capacity)" << endl;

    return 0;
}