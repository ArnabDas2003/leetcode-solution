class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int maxSum = nums[0];  // Initialize with the first element
    int currentSum = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        currentSum = max(nums[i], currentSum + nums[i]);  // either start new or extend
        maxSum = max(maxSum, currentSum);  // update max
    }

    return maxSum;

    }
};