class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Step 1: Count frequencies
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        // Step 2: Find the maximum frequency
        int maxFreq = 0;
        for (unordered_map<int,int>::iterator it = freq.begin(); it != freq.end(); it++) {
            if (it->second > maxFreq) {
                maxFreq = it->second;
            }
        }

        // Step 3: Count how many elements have frequency == maxFreq
        int total = 0;
        for (unordered_map<int,int>::iterator it = freq.begin(); it != freq.end(); it++) {
            if (it->second == maxFreq) {
                total += it->second;
            }
        }

        return total;
    }
};
