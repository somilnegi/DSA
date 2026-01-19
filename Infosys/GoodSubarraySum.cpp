#include <bits/stdc++.h>
using namespace std;

int goodSubarraySum(vector<int> &arr, int n, int k)
{
    if (k == 0)
        return 0;
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + arr[i];
    }
    unordered_map<int, int> mp;
    deque<int> dq;
    int left = 0;
    int maxSum = 0;
    int currSum = 0;
    for (int right = 0; right < n; right++)
    {
        mp[arr[right]]++;
        while (mp.size() > k)
        {
            mp[arr[left]]--;
            if (mp[arr[left]] == 0)
            {
                mp.erase(arr[left]);
            }
            left++;
        }
        while (!dq.empty() && dq.front() < left)
        {
            dq.pop_front();
        }
        while (!dq.empty() && pref[dq.back()] >= pref[right])
        {
            dq.pop_back();
        }
        dq.push_back(right);
        if (!dq.empty())
        {
            maxSum = max(maxSum, pref[right + 1] - pref[dq.front()]);
        }
    }
    return maxSum;

}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<goodSubarraySum(arr, n, k) << endl;
    return 0;
}