#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int s, int e, int k){
    if(s>e){
        return false;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==k){
        return true;
    }
    if(arr[mid]<k){
        binarySearch(arr,mid+1,e,k);
    }
    else{
        binarySearch(arr,s,mid-1,k);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int el;
    cin>>el;
    if(binarySearch(arr,0,n,el)){
        cout<<"Element present"<<endl;
    }
    else{
        cout<<"Element not present"<<endl;
    }
    return 0;
}