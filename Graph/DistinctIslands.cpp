#include<bits/stdc++.h>
using namespace std;
void dfs(int n, int m, int row, int col, vector<vector<int>> &vis, int** arr, vector<pair<int, int>> &vec, int row0, int col0) {
    vis[row][col]=1;
    vec.push_back({row-row0, col-col0});
    int delrow[]={-1, 0, 1, 0};
    int delcol[]={0, -1, 0, 1};
    for(int i=0; i<4; i++) {
        int nrow=row+delrow[i];
        int ncol=row+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && arr[nrow][ncol]==1) {
            dfs(n, m, nrow, ncol, vis, arr, vec, row0, col0);
        }
    }
}

int distinctIslands(int** arr, int n, int m){
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!vis[i][j] && arr[i][j]) {
                vector<pair<int, int>> vec;
                dfs(n, m, i, j, vis, arr, vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}