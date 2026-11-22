
#include <iostream>
using namespace std;

int main()
{
    int n;
    int cost[10][10];
    int visited[10] = {0};
    int minCost = 99999;

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    int path[10], bestPath[10];
    int currentCost = 0;

    // Start from city 0
    visited[0] = 1;
    path[0] = 0;

    // Try all possible paths
    int total = 1;

    for (int i = 1; i < n; i++)
        total *= i;

    for (int p = 0; p < total; p++)
    {
        int tempVisited[10] = {0};
        tempVisited[0] = 1;

        int tempPath[10];
        tempPath[0] = 0;

        int x = p;
        int fact = total;

        for (int i = 1; i < n; i++)
        {
            int count = n - i;
            fact /= count;

            int index = x / fact;
            x %= fact;

            int j = 1;
            while (index >= 0)
            {
                if (!tempVisited[j])
                {
                    if (index == 0)
                        break;
                    index--;
                }
                j++;
            }

            tempPath[i] = j;
            tempVisited[j] = 1;
        }

        int c = 0;

        for (int i = 0; i < n - 1; i++)
            c += cost[tempPath[i]][tempPath[i + 1]];

        c += cost[tempPath[n - 1]][0];

        if (c < minCost)
        {
            minCost = c;

            for (int i = 0; i < n; i++)
                bestPath[i] = tempPath[i];
        }
    }

    cout << "\nMinimum travelling cost: " << minCost;
    cout << "\nShortest path: ";

    for (int i = 0; i < n; i++)
        cout << bestPath[i] + 1 << " -> ";

    cout << 1 << endl;

    return 0;
}
