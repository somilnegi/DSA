#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> Q(n, vector<char> (m));
    queue<pair<int, int>> q;
    int enemyCount=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>Q[i][j];
            if(Q[i][j]=='A') {
                q.push({i, j});
            }
            else if(Q[i][j]=='E') {
                enemyCount++;
            }
        }
    }
    if(enemyCount==0) {
        cout<<"0"<<endl;
        return 0;
    }
    int time=0; int invadedCount=0;
    int dx[]={-1, 1, 0, 0};
    int dy[]={0, 0, -1, 1};
    while(!q.empty()) {
        int size=q.size();
        bool invadedThisSecond=false;
        for(int i=0; i<size; i++) {
            pair<int, int> curr=q.front();
            q.pop();
            for(int d=0; d<4; d++) {
                int nx=curr.first+dx[d];
                int ny=curr.second+dy[d];

                if(nx>=0 && nx<n && ny>=0 && ny<m && Q[nx][ny]=='E') {
                    Q[nx][ny]='A';
                    invadedCount++;
                    q.push({nx, ny});
                    invadedThisSecond=true;
                }
            }
        }
        if(invadedThisSecond) time++;
    }
    cout<<((invadedCount==enemyCount)? time: -1)<<endl;
    return 0;
}