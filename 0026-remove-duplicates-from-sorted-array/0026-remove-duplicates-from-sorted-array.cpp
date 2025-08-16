class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[count]){
                count++;
                nums[count]=nums[i];
            }
        }
        return count+1;
    }
};