class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
           vector<int> ans;
        int k = nums.size();

        // First half: x1, x2, ..., xn
        for (int i = 0; i < n; i++) {
            ans.push_back(nums[i]);      // take xi
            ans.push_back(nums[i + n]);  // take yi
        }

        return ans;
    }
};