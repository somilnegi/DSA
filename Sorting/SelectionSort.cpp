#include<bits/stdc++.h>
using namespace std;
// The average, best and worst TC of Selection Sort is O(n^2) because in every case the array is traversed 2 times  & the SC is O(1)
// It is used only when the size of data structure is small
// It is unstable as the relative order is not preserved and it is in-place as no extra space is required
void SelectionSort(vector<int> &arr, int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
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
    SelectionSort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}