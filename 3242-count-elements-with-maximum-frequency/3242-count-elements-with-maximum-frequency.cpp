class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};   // frequency array

        // count frequencies
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        // find max frequency
        int maxFreq = 0;
        for (int i = 1; i <= 100; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
            }
        }

        // count total elements with max frequency
        int total = 0;
        for (int i = 1; i <= 100; i++) {
            if (freq[i] == maxFreq) {
                total += freq[i];
            }
        }

        return total;
    }
};
