class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum=nums[0];
        int maxsum=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            currentsum=max(nums[i],currentsum+nums[i]);
            maxsum=max(currentsum,maxsum);
        }
        return maxsum;
    }
};