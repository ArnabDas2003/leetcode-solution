class Solution {
public:
    string reverseWords(string s) {
         stringstream ss(s);
        string word, ans = "";
        while (ss >> word) { 
            ans = word + " " + ans; // put word at front
        }
        // remove last space
        if (!ans.empty()) ans.pop_back();
        return ans;
    }
};