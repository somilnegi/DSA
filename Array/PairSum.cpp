#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> res;
   for(int i=0;i<arr.size();i++){
      for(int j=i+1;j<arr.size();j++){
         if(arr[i]+arr[j]==s){
            vector<int> temp;
            temp.push_back(min(arr[i],arr[j]));
            temp.push_back(max(arr[i],arr[j]));
            res.push_back(temp);
         }
      }
   }
   sort(res.begin(), res.end());
   return res;
}

// The below solution is same as above in terms of logic but it is more optimised
vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> res;
   sort(arr.begin(),arr.end());
   for(int i=0;i<arr.size();i++){
      for(int j=i+1;j<arr.size();j++){
         if(arr[i]+arr[j]==s){
            res.push_back({arr[i],arr[j]});
         }
         else if(arr[i]+arr[j]>s){
            break;
         }
         else{
            continue;
         }
      }
   }
   return res;
}