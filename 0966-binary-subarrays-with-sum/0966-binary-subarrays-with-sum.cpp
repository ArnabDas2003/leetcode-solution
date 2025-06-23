#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // handles subarrays starting from index 0

        int prefix_sum = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];

            if (prefixSumCount.find(prefix_sum - goal) != prefixSumCount.end()) {
                count += prefixSumCount[prefix_sum - goal];
            }

            prefixSumCount[prefix_sum]++;
        }

        return count;
    }
};
