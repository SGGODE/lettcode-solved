class Solution {
private:
  
    int sub(vector<vector<vector<int>>>&dp,vector<int>&nums,int index,int buy,int n,int cap){
        if(index==n||cap==0){
            return 0;
        }
        if(dp[index][buy][cap]!=-1)return dp[index][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-nums[index]+sub(dp,nums,index+1,0,n,cap),sub(dp,nums,index+1,1,n,cap));
        }else{
            profit=max(nums[index]+sub(dp,nums,index+1,1,n,cap-1),sub(dp,nums,index+1,0,n,cap));
        }
        return dp[index][buy][cap]=profit;
    }
public:
    int maxProfit(vector<int>&nums) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return sub(dp,nums,0,1,n,2);
    }
};