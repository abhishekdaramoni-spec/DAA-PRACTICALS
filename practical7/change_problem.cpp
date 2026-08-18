#include <iostream>
#include <vector>
#include <chrono>
#include <climits>
using namespace std;

int minCoins(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount];
}

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    auto start = chrono::high_resolution_clock::now();

    int result = minCoins(coins, amount);

    auto end = chrono::high_resolution_clock::now();

    auto executionTime =
        chrono::duration_cast<chrono::nanoseconds>(end - start);

    if (result == INT_MAX)
    {
        cout << "\nChange cannot be made for the given amount." << endl;
    }
    else
    {
        cout << "\nMinimum number of coins = " << result << endl;
    }

    cout << "Execution Time = "
         << executionTime.count()
         << " nanoseconds" << endl;

    cout << "Time Complexity = O(n * amount)" << endl;
    cout << "Space Complexity = O(amount)" << endl;

    return 0;
}
