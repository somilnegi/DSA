#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int start=0,end=n-1;
    int mid=start+((end-start)/2);

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(key>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+((end-start)/2);
    }
    return -1;
}

int main(){
    int even[6]={2,4,6,8,10,12};
    int odd[5]={2,5,6,9,15};

    cout<<binarySearch(even,6,18)<<endl;
    cout<<binarySearch(odd,5,5)<<endl;;

    return 0;
}