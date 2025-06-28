class Solution {
public:
bool isPossible(vector<int> piles, int mid, int h){
        long long hours = 0;
        for (int bananas : piles) {
            hours += (bananas + mid - 1) / mid; // Efficient ceiling calculation
            if (hours > h) return false; // Early exit if hours exceed limit
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(), piles.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(piles, mid, h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};