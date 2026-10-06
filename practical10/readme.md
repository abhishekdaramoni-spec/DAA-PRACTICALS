Summary
Kruskal’s Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a weighted, undirected graph. It sorts all edges by weight and selects the smallest edges while using the find() and union() functions to avoid cycles. The algorithm stops after selecting V-1 edges.
Conclusion
Kruskal’s Algorithm efficiently finds the minimum-cost way to connect all vertices of a graph without forming cycles. By using Find and Union operations, cycle detection becomes simple and efficient. Its overall time complexity is O(E log E) due to sorting the edges.
