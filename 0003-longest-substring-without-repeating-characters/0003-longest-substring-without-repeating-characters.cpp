class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         if(s.empty()) return 0;
        int k = s.length();
        int curr = 0;
        int longest = 0;
        int lastIndex[256]; 
        for(int i=0;i<256;i++) lastIndex[i] = -1;

        int start = 0;
        for(int i = 0; i < k; i++) {
            if(lastIndex[s[i]] >= start) {
                start = lastIndex[s[i]] + 1;
            }
            lastIndex[s[i]] = i;
            curr = i - start + 1;
            longest = max(longest, curr);
        }
        return max(longest, curr);
    }
};