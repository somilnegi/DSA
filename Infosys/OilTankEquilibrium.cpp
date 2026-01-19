#include<bits/stdc++.h>
using namespace std;

int countDisturbances(vector<int>& A, int n, int c, int x) {
    int currentOil=x;
    int disturbances=0;
    for(int action: A) {
        if(action==1) {
            if(currentOil<c) {
                currentOil++;
            }
            else {
                disturbances++;
            }
        }
        else {
            if(currentOil>0) {
                currentOil--;
            }
            else {
                disturbances++;
            }
        }
    }
    return disturbances;
}

int main() {
    int n,c;
    cin>>n>>c;
    vector<int> A(n);
    for(int i=0; i<n; i++) {
        cin>>A[i];
    }
    int minDisturbances=n+1;
    int bestX=0;
    for(int x=0; x<=c; x++) {
        int d=countDisturbances(A, n, c, x);
        if(d<minDisturbances) {
            minDisturbances=d;
            bestX=x;
        }
    }
    cout<<bestX<<endl;
    return 0;
}