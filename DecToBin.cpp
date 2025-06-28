#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    string ans = "";
    int i=0;

    while(n!=0){
        int bit = n & 1;
        ans = to_string(bit) + ans;

        n = n>>1;
        i++;
    }
    cout<<ans<<endl;
}