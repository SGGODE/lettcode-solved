class Solution {
private:
    int sub(vector<vector<vector<int>>>&dp,vector<int>&nums,int index,int n,int buy,int cap){
        if(cap==0)return 0;
        if(index==n)return 0;
        if(dp[index][buy][cap]!=-1)return dp[index][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-nums[index]+sub(dp,nums,index+1,n,0,cap),sub(dp,nums,index+1,n,1,cap));
        }
        else{
            profit=max(nums[index]+sub(dp,nums,index+1,n,1,cap-1),sub(dp,nums,index+1,n,0,cap));
        }
        return dp[index][buy][cap]=profit;
    }
public:
    int maxProfit(int k, vector<int>&nums) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return sub(dp,nums,0,n,1,k);
    }
};