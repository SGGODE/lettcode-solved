class Solution {
private:
    int sub(vector<int>&dp,vector<int>&nums,int index,int target){
        if(target==0)return 1;
        if(index==nums.size())return 0;
       // int notpick = sub(nums,index+1,target);
        if(dp[target]!=-1)return dp[target];
        int pick = 0;
        for(int i=0;i<nums.size();i++){
         if(target>=nums[i]){
             pick += sub(dp,nums,index,target-nums[i]);
         }
        }
        return dp[target]=pick;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return sub(dp,nums,0,target);
    }
};