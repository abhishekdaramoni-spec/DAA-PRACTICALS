#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <chrono>

using namespace std;
using namespace chrono;

// BFS using Queue
void BFS(vector<vector<int>> &graph, int start)
{
    int n = graph.size();

    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbour : graph[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    cout << endl;
}

// DFS using Stack
void DFS(vector<vector<int>> &graph, int start)
{
    int n = graph.size();

    vector<bool> visited(n, false);
    stack<int> s;

    s.push(start);

    cout << "DFS Traversal: ";

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        if (!visited[node])
        {
            visited[node] = true;

            cout << node << " ";

            // Add neighbours to stack
            // in reverse order to get a natural traversal
            for (int i = graph[node].size() - 1; i >= 0; i--)
            {
                int neighbour = graph[node][i];

                if (!visited[neighbour])
                {
                    s.push(neighbour);
                }
            }
        }
    }

    cout << endl;
}

int main()
{
    // Same graph for both BFS and DFS
    int n = 7;

    vector<vector<int>> graph(n);

    // Creating the graph
    graph[0] = {1, 2};
    graph[1] = {3, 4};
    graph[2] = {5};
    graph[3] = {};
    graph[4] = {6};
    graph[5] = {};
    graph[6] = {};

    cout << "Graph Traversal\n";
    cout << "---------------\n\n";

    // BFS
    auto startBFS = high_resolution_clock::now();

    BFS(graph, 0);

    auto endBFS = high_resolution_clock::now();

    auto bfsTime =
        duration_cast<nanoseconds>(endBFS - startBFS).count();

    // DFS
    auto startDFS = high_resolution_clock::now();

    DFS(graph, 0);

    auto endDFS = high_resolution_clock::now();

    auto dfsTime =
        duration_cast<nanoseconds>(endDFS - startDFS).count();

    cout << "\nExecution Time:\n";
    cout << "BFS: " << bfsTime << " nanoseconds\n";
    cout << "DFS: " << dfsTime << " nanoseconds\n";

    return 0;
}
