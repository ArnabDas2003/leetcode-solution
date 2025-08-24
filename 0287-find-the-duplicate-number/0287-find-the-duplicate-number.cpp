class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>seen;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(seen.find(num)!=seen.end()){
                return num;
            }
            seen.insert(num);
        }
        return -1;
    }
};