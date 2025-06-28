#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){
    if(n==0){ //If 0 is considered as 1st term then put n==1 here
        return 0;
    }
    if(n==1){ //If 0 is considered as 1st term then put n==2 here
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<fibonacci(n)<<endl;
    return 0;
}