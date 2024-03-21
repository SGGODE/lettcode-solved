class Solution {
private:
    int sub(vector<int>&nums,vector<vector<int>>&dp,int index,int sum){
        if(index<0)return sum==0?0:-1e9;
        if(dp[index][sum]!=-1)return dp[index][sum];
        int notpick = sub(nums,dp,index-1,sum);
        int pick = nums[index]+sub(nums,dp,index-1,(sum+nums[index])%3);
        return dp[index][sum]=max(pick,notpick);
    }
    
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return max(0,sub(nums,dp,n-1,0));
    }
};