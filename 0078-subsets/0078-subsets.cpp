class Solution {
public:
    void helper(int index, vector<int>&nums, vector<int>&path, vector<vector<int>>&result){
        result.push_back(path);
        int i;
        for(i=index;i<nums.size();i++){
            path.push_back(nums[i]);
            helper(i+1,nums,path,result);
            path.pop_back();

        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int>path;
        helper(0,nums,path,result);
        return result;
    }
};