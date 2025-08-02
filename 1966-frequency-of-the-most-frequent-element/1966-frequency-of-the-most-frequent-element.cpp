class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
         sort(nums.begin(), nums.end());
        long long left = 0, total = 0;
        int res = 0;

        for (int right = 0; right < nums.size(); ++right) {
            total += nums[right];

            while ((long long)(right - left + 1) * nums[right] - total > k) {
                total -= nums[left];
                left++;
            }

          res = max(res, (int)(right - left + 1));

        }

        return res;
    }
};