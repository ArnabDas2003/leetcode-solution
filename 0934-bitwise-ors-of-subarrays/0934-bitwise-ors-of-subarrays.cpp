class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;       // To store all unique OR results
        unordered_set<int> cur;       // Current OR results ending at current index

        for (int num : arr) {
            unordered_set<int> next;
            next.insert(num);         // Start new subarray with num

            for (int val : cur) {
                next.insert(val | num);  // Extend previous subarrays
            }

            cur = next;               // Update current set
            for (int val : cur) {
                res.insert(val);      // Add to result set
            }
        }

        return res.size();            // Total unique OR results
    }
};
