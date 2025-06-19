class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            // n >>= 1;
            n/=2;
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        // Bubble sort with swap allowed only if set bits count matches
        for (int i = 0; i < n; i++) {
            bool check = false;
            for (int j = 0; j < n - 1; j++) {
                if (countSetBits(nums[j]) == countSetBits(nums[j + 1]) && nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    check = true;
                }
            }
            if (!check) break;
        }

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) return false;
        }

        return true;
    }
};
