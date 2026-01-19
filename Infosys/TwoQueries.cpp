#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int q;
    int totalSum=0;
    cin>>q;
    for(int i=0; i<q; i++) {
        int type, l, r;
        cin>>type>>l>>r;
        if(type==1) {
            int valAtl=arr[l];
            for(int i=l; i<=r; i++) {
                arr[i]=(i-l+1)*valAtl;
            }
        }
        else {
            for(int i=l; i<=r; i++) {
                totalSum+=arr[i];
            }
        }
    }
    cout<<totalSum<<endl;
    return 0;
}