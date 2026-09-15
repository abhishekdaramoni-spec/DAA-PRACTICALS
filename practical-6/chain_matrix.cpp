#include <iostream>
#include <vector>
#include <climits>
#include <chrono>

using namespace std;
using namespace chrono;

long long matrixChainMultiplication(const vector<int> &p, int n)
{
    // dp[i][j] = minimum cost to multiply Ai...Aj
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    // length = number of matrices in the chain
    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++)
            {
                long long cost =
                    dp[i][k] +
                    dp[k + 1][j] +
                    1LL * p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n];
}

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of matrices." << endl;
        return 0;
    }

    vector<int> dimensions(n + 1);

    cout << "\nEnter dimensions for matrices:\n";

    for (int i = 0; i <= n; i++)
    {
        cout << "Dimension " << i + 1 << ": ";
        cin >> dimensions[i];
    }

    // Start timer
    auto start = high_resolution_clock::now();

    long long minimumCost =
        matrixChainMultiplication(dimensions, n);

    // Stop timer
    auto end = high_resolution_clock::now();

    auto executionTime =
        duration_cast<nanoseconds>(end - start);

    cout << "\n----------------------------------\n";
    cout << "Minimum scalar multiplications: "
         << minimumCost << endl;

    cout << "Execution Time: "
         << executionTime.count()
         << " nanoseconds" << endl;

    cout << "Time Complexity: O(n^3)" << endl;
    cout << "Space Complexity: O(n^2)" << endl;
    cout << "----------------------------------\n";

    return 0;
}
