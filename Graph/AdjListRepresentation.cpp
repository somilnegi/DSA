#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createGraph(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);

    // Add each edge to the adjacency list
    for (auto &it : edges) {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        // since the graph is undirected
        adj[v].push_back(u);
  
    }
    return adj;
}

int main() {
    int V = 3;

    // List of edges (u, v)
    vector<vector<int>> edges = { {1, 0}, {1, 2}, {2, 0} };

    // Build the graph using edges
    vector<vector<int>> adj = createGraph(V, edges);

    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < V; i++) {
        
        // Print the vertex
        cout << i << ": "; 
        for (int j : adj[i]) {
            
            // Print its adjacent
            cout << j << " "; 
        }
        cout << endl; 
    }

    return 0;
}