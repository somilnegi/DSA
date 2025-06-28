#include<bits/stdc++.h>
using namespace std;

// int findDuplicate(vector<int> &arr){
//     unordered_map<int, int> mp;
//     for(int i=0; i<arr.size(); i++){
//         mp[arr[i]]++;
//     }
//     for(auto it: mp){
//         if(it.second==2){
//             return it.first;
//         }
//     }
// }

// Using XOR
int findDuplicate(vector<int> &arr){
    int ans=0;
    // XOR all array elements
    for(int i=0; i<arr.size(); i++){
        ans=ans^arr[i];
    }

    // XOR 1 to n-1 
    // By this all the elements will become zero and only the duplicate element will be left
    for(int i=1; i<arr.size(); i++){
        ans=ans^i;
    }
    return ans;
}

int main(){
    vector<int> arr={4, 2, 1, 3, 1};
    cout<<findDuplicate(arr);
}