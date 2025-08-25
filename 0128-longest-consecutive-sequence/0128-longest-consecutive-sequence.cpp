class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if (nums.empty()) return 0;

    unordered_set<int> s(nums.begin(), nums.end()); // O(n)
    int longest = 0;

    for (int num : s) { // iterate over set, avoids duplicates
        if (!s.count(num - 1)) { // only start if it's the beginning of a sequence
            int curr = num;
            int streak = 1;

            while (s.count(curr + 1)) {
                curr++;
                streak++;
            }

            longest = max(longest, streak);
        }
    }
    return longest;
    }
};