#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void floydWarshall(vector<vector<int>> &dist, int V)
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // Avoid adding infinity
                if (dist[i][k] != INT_MAX &&
                    dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    cout << "Shortest Distance Matrix:\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INT_MAX)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int V = 4;

    vector<vector<int>> dist = {
        {0, 5, INT_MAX, 10},
        {INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 1},
        {INT_MAX, INT_MAX, INT_MAX, 0}};

    floydWarshall(dist, V);

    return 0;
}
