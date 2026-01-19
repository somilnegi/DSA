#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &result) {
    vis[node]=true;
    result.push_back(node);
    for(int i: adj[node]) {
        if(!vis[i]) {
            dfs(i, adj, vis, result);
        }
    }
}

int main() {
    vector<vector<int>> edges = {{0, 1},{0, 2},{1, 2}};
    int V=3;
    vector<vector<int>> adj(V);
    for (auto &it : edges) {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        // since the graph is undirected
        adj[v].push_back(u);
  
    }
    vector<int> res;
    vector<bool> vis(V, false);
    dfs(0, adj, vis, res);
    for(int i: res) {
        cout<<i<<" ";
    }
    return 0;
}