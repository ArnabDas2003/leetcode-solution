class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
    int i = n - 2;

    // Step 1: find first decreasing element
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // Step 2: if found, find just larger element on right side
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]); // Step 3: swap
    }

    // Step 4: reverse the right part
    reverse(nums.begin() + i + 1, nums.end());
    }
};