#include<bits/stdc++.h>
using namespace std;

unordered_map<long long, int> memo;

int solve(int n) {
    if(n<=1) return 0;
    if(memo.count(n)) return memo[n];
    int res=1+solve(n-1);
    res=min(res, 1+solve(n-(n/2)));
    res=min(res, 1+solve(n-(2*n/3)));
    return memo[n]=res;
}

int main() {
    int n;
    cin>>n; 
    cout<<solve(n)<<endl;
    return 0;
}