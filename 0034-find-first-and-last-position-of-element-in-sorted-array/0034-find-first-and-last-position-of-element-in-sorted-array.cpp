class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                first=i;
                break;
            }
        }
        int last=-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==target){
                last=i;
                break;
            }
        }
        return {first,last};
        
    }
};