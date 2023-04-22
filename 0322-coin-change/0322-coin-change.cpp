class Solution {
private:
    int fun(vector<int>&coins,int index,int sum,vector<vector<int>>&dp){
        if(index==0){
            if(sum%coins[0]==0)return sum/coins[0];
            return 1e9;
        }
        if(dp[index][sum]!=-1)return dp[index][sum];
        int notpick=0+fun(coins,index-1,sum,dp);
        int pick=INT_MAX;
        if(sum>=coins[index]){
            pick=1+fun(coins,index,sum-coins[index],dp);
        }
        return dp[index][sum]=min(pick,notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        long long int x = fun(coins,n-1,amount,dp);
        if(x==1e9)return -1;
        return x;
    }
};