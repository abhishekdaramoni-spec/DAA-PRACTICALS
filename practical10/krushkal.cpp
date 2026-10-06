#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
};

// Find function
int find(int parent[], int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent, parent[x]);
}

// Union function
void unionSet(int parent[], int rank[], int u, int v)
{
    u = find(parent, u);
    v = find(parent, v);

    if (u != v)
    {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int main()
{
    int V = 4;

    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    // Sort edges according to weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b)
         {
             return a.weight < b.weight;
         });

    int parent[V];
    int rank[V] = {0};

    // Initially every vertex is its own parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;
    int count = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (Edge e : edges)
    {
        int u = find(parent, e.u);
        int v = find(parent, e.v);

        // If vertices belong to different sets
        if (u != v)
        {
            cout << e.u << " - " << e.v
                 << " : " << e.weight << endl;

            totalCost += e.weight;
            count++;

            unionSet(parent, rank, u, v);

            if (count == V - 1)
                break;
        }
    }

    cout << "Minimum Cost = " << totalCost << endl;

    return 0;
}
