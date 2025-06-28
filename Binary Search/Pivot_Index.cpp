class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            int sumleft=accumulate(nums.begin(),nums.begin()+mid, 0);
            int sumright=accumulate(nums.begin()+mid+1,nums.end(), 0);
            if(sumleft==sumright){
                return mid;
            }
            else if(sumleft<sumright){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0); 
        int leftSum = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};