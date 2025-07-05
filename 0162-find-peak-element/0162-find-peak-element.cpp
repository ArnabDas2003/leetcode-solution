class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            bool isPeak = true;

            // check left
            if (i > 0 && nums[i] < nums[i - 1]) {
                isPeak = false;
            }

            // check right
            if (i < nums.size() - 1 && nums[i] < nums[i + 1]) {
                isPeak = false;
            }

            if (isPeak) {
                return i; // return index of peak
            }
        }

        return -1; // agar koi peak na mile (edge case)
    }
};
