#include<bits/stdc++.h>
using namespace std;

void swapAlternate(int arr[], int size){
    for(int i=0;i<size;i+=2){
        if(i+1<size){
            swap(arr[i],arr[i+1]);
        }
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int even[8]={5,2,9,4,7,6,1,0};
    int odd[7]={11,7,31,17,9,0,24};

    swapAlternate(even, 8);
    printArray(even, 8);

    swapAlternate(odd, 7);
    printArray(odd, 7);
    return 0;
}