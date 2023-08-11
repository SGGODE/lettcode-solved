class Solution {
private:
    int sub(vector<vector<int>>&dp,vector<int>&nums,int sum,int index){
        if(sum==0){
            return 1;
        }
        if(index==nums.size()){
            return 0;
        }
        if(dp[index][sum]!=-1)return dp[index][sum];
        int notpick=sub(dp,nums,sum,index+1);
        int pick=0;
        if(sum>=nums[index]){
            pick=sub(dp,nums,sum-nums[index],index);
        }
        return dp[index][sum]=pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return sub(dp,coins,amount,0);
    }
};