class Solution {
public:
    void helper(int index, vector<int>&nums, vector<int>&path, vector<vector<int>>&result){
        int i;
        result.push_back(path);
        for(i=index;i<nums.size();i++){
            if(i>index&&nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            helper(i+1,nums,path,result);
            path.pop_back();
            
        }
    

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>>result;
         vector<int>path;
         helper(0,nums,path,result);
         return result;
    }
};