#include <bits/stdc++.h> 
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;
	unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[arr1[i]]++;
    }
    for (int i = 0; i < m; i++) {
        if (freq[arr2[i]] > 0) {
            ans.push_back(arr2[i]);  
            freq[arr2[i]]--;       
        }
    }

    return ans;
}

// Without using extra data structure
// vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
// {
//     vector<int> ans;
// 	int i=0,j=0;
//     while(i<n && j<m){
//         if(arr1[i]==arr2[j]){
//             ans.push_back(arr1[i]);
//             i++;
//             j++;
//         }
//         else if(arr1[i]>arr2[j]){
//             j++;
//         }
//         else{
//             i++;
//         }
//     }
//     return ans;
// }

int main(){
    vector<int> arr1={1,2,2,2,3,4};
    vector<int> arr2={2,2,3,3};
    vector<int> res=findArrayIntersection(arr1,6,arr2,4);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}