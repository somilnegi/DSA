#include<bits/stdc++.h>
using namespace std; 
// Without base case the function call stack is overflowed which causes segmentation fault
int factorial(int n){
    if(n==1||n==0){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}