class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> maxheap;
        set<int> seen;

        // Push all elements into maxheap
        for (int i = 0; i < nums.size(); i++) {
            maxheap.push(nums[i]);
        }

        int count = 0;
        int ans = maxheap.top(); // In case less than 3 distincts

        while (!maxheap.empty()) {
            int top = maxheap.top();
            maxheap.pop();

            // Only consider if not seen before (distinct)
            if (seen.find(top) == seen.end()) {
                seen.insert(top);
                count++;
                if (count == 3) {
                    ans = top;
                    break;
                }
            }
        }

        return ans;
    }
};
