#include<bits/stdc++.h>
using namespace std;
// The average, best and worst TC of insertion Sort is O(n^2) & SC is O(1)
// The best case TC can be imporved to 0(n) by adding a flag
// For every ith round the ith largest element is send to its right location
// It is stable and in-place

void InsertionSort(vector<int> &arr, int n){
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 & arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    InsertionSort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}