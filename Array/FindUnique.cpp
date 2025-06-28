#include<bits/stdc++.h>
using namespace std;

int findUnique(int arr[], int size){
    int result=0;
    for(int i=0;i<size;i++){
        result=result^arr[i];
    }
    return result;
}

int main(){
    int arr[7]={2,3,1,6,3,2,6};
    cout<<findUnique(arr,7)<<endl;
    return 0;
}