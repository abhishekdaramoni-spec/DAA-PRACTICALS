#include <iostream>
#include <climits>
#include <vector>
#include <tuple>

using namespace std;

#define V 5

void primMST(vector<tuple<char, char, int>> edges)
{
    char parent[V];
    int key[V];
    bool visited[V];

    // Initialize
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = false;
        parent[i] = '-';
    }

    // Start from A
    key[0] = 0;

    // Prim's Algorithm
    for (int count = 0; count < V; count++)
    {
        int min = INT_MAX;
        int u = -1;

        // Find vertex with minimum key
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && key[v] < min)
            {
                min = key[v];
                u = v;
            }
        }

        visited[u] = true;

        // Update key values
        for (auto edge : edges)
        {
            char a = get<0>(edge);
            char b = get<1>(edge);
            int weight = get<2>(edge);

            int x = a - 'A';
            int y = b - 'A';

            // A -> B
            if (x == u && !visited[y] && weight < key[y])
            {
                parent[y] = a;
                key[y] = weight;
            }

            // B -> A
            if (y == u && !visited[x] && weight < key[x])
            {
                parent[x] = b;
                key[x] = weight;
            }
        }
    }

    // Print MST
    int total = 0;

    cout << "Edge\tWeight" << endl;

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - "
             << char('A' + i)
             << "\t" << key[i] << endl;

        total += key[i];
    }

    cout << "\nTotal MST Weight = "
         << total << endl;
}

int main()
{
    // Graph: [Source, Destination, Weight]
    vector<tuple<char, char, int>> edges =
        {
            {'A', 'B', 2},
            {'A', 'D', 6},
            {'B', 'C', 3},
            {'B', 'D', 8},
            {'B', 'E', 5},
            {'C', 'E', 7},
            {'D', 'E', 9}};

    primMST(edges);

    return 0;
}
