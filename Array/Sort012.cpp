#include <bits/stdc++.h> 
// Just count the frequency of 0, 1 and 2
void sort012(int *arr, int n)
{ 
    int c0=0,c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            c0++;
        }
        else if(arr[i]==1){
            c1++;
        }
        else{
            c2++;
        }
    }
    for(int i=0;i<n;i++){
        if(c0>0){
            arr[i]=0;
            c0--;
        }
        else if(c1>0){
            arr[i]=1;
            c1--;
        }
        else{
            arr[i]=2;
            c2--;
        }

    }
}

// Dutch National Flag or 3 pointer approach
void sort012(int *arr, int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low], arr[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high]);
                high--;
                break;
        }
    }
}

