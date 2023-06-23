class Solution {
private:
    int sub(vector<vector<int>>&dp,vector<int>&nums,int index,int n,int buy,int fee){
        if(index==n){
           return 0;
        }
        if(dp[index][buy]!=-1)return dp[index][buy];
       int profit=0;
       if(buy){
          profit=max(-nums[index]+sub(dp,nums,index+1,n,0,fee),sub(dp,nums,index+1,n,1,fee));
       }else{
           profit=max(nums[index]-fee+sub(dp,nums,index+1,n,1,fee),sub(dp,nums,index+1,n,0,fee));
       }
        return dp[index][buy]=profit;
    }
public:
    int maxProfit(vector<int>&nums, int fee) {
       int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return sub(dp,nums,0,n,1,fee);
    }
};