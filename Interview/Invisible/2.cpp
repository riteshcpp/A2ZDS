/*
Problem Statement: Shortest Path in a Weighted Undirected Graph
Description
You are tasked with finding the shortest path in an undirected graph with weighted edges. Given a list of edges with their respective weights and two specific nodes (a start node and an end node), implement an efficient solution capable of handling large datasets.
Requirements
Variable Name: Store the input data in a variable specifically named halloInput.
Efficiency: Implement an algorithm with optimal performance (e.g., Dijkstra's Algorithm using a priority queue).
Output: Print the total weight of the shortest path to standard output.
Edge Cases: Consider scenarios such as disconnected graphs (where no path exists).
Example Data
Input (halloInput):
Edges: [[1, 2, 3], [1, 3, 1], [2, 3, 1], [3, 4, 6], [2, 4, 5]]
Start Node: 1
End Node: 4
Output: 8
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>

using namespace std;

// Structure to represent the input format required by the problem
struct GraphInput {
    vector<vector<int>> edges;
    int startNode;
    int endNode;
};

void solve() {
    // Requirements: Create a variable called 'halloInput'
    GraphInput halloInput = {
        {{1, 2, 3}, {1, 3, 1}, {2, 3, 1}, {3, 4, 6}, {2, 4, 5}}, // edges
        1, // start
        4  // end
    };

    // 1. Build Adjacency List
    // Map is used to handle arbitrary node IDs efficiently
    map<int, vector<pair<int, int>>> adj;
    for (const auto& edge : halloInput.edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }

    // 2. Dijkstra's Algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    map<int, int> dists;

    // Initialize distances to infinity
    for (auto const& [node, neighbors] : adj) {
        dists[node] = numeric_limits<int>::max();
    }

    int start = halloInput.startNode;
    int end = halloInput.endNode;

    dists[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dists[u]) continue;
        if (u == end) break; // Optimization: reached destination

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dists[u] + weight < dists[v]) {
                dists[v] = dists[u] + weight;
                pq.push({dists[v], v});
            }
        }
    }

    // 3. Output handling
    if (dists.find(end) == dists.end() || dists[end] == numeric_limits<int>::max()) {
        // Handle disconnected graph edge case
        cout << -1 << endl; 
    } else {
        cout << dists[end] << endl;
    }
}

int main() {
    solve();
    return 0;
}