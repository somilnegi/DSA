#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int n=arr.size();
        int max_length=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if (sum == k) {
                max_length = i + 1;
            }
            if (mp.find(sum - k) != mp.end()) {
                max_length = max(max_length, i - mp[sum - k]);
            }
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        
        return max_length;
    }
};

// TC : O(n^2)
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        long long s = 0; // Sum variable
        for (int j = i; j < n; j++) { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += a[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}