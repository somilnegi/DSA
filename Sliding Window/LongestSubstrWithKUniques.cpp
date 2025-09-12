#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string &s, int k) {
    vector<int> freq(26, 0);
    int l=0, r=0, maxi=0, cnt=0;
    int n=s.length();
    while(r<n) {
        freq[s[r]-'a']++;
        if(freq[s[r]-'a']==1) {
            cnt++;
        }
        if(cnt>k) {
            freq[s[l]-'a']--;
            if(freq[s[l]-'a']==0) {
                cnt--;
            }
            l++;
        }
        if(cnt==k) {
            maxi=max(maxi, r-l+1);
        }
        r++;
    }
    return maxi;
}

int main() {
    string s="aabacbebebe";
    int k=3;
    cout<<longestKSubstr(s, k);
    return 0;
}
    