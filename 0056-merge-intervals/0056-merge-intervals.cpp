class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;

    for (auto interval : intervals) {
        // If merged is empty OR current interval does not overlap with last merged interval
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            // Overlap case: merge the intervals
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    return merged;
    }
};