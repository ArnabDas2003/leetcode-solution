class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n; // wrap around
        if (nums[i] > nums[next]) {
            count++;
        }
    }

    // At most 1 drop allowed
    return count <= 1;
    }
};