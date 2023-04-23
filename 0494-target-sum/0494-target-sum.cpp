class Solution {
private:
    int fun(vector<int>&nums,int index,int sum,vector<vector<int>>&dp){
        if(index==0){
            if(nums[0]==0&&sum==0)return 2;
            return (nums[0]==sum)||(sum==0);
        }
        if(dp[index][sum]!=-1)return dp[index][sum];
        int notpick=fun(nums,index-1,sum,dp);
        int pick=0;
        if(sum>=nums[index]){
            pick=fun(nums,index-1,sum-nums[index],dp);
        }
        return dp[index][sum]=pick+notpick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i:nums)sum+=i;
        if(sum-target<0||(sum-target)%2==1)return 0;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(((sum-target)/2)+1,-1));
        return fun(nums,n-1,((sum-target)/2),dp);
    }
};