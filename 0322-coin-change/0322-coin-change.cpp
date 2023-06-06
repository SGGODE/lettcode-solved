class Solution {
private:
    int mincnt=INT_MAX;
    int combination(vector<int>&coins,vector<vector<int>>&dp,int sum,int index,int cnt){
        // if(sum==0){
        //    // cout<<cnt<<endl;
        //     mincnt=min(mincnt,cnt);
        //     return 1;
        // }
        if(index==0){
            if(sum%coins[index]==0){
                // cnt+=(sum/coins[index]);
                // mincnt=min(mincnt,cnt);
                return sum/coins[index];
            }
            //return sum%coins[index]==0;
            return 1e9;
        }
        if(dp[index][sum]!=-1)return dp[index][sum];
        int notpick=0+combination(coins,dp,sum,index-1,cnt);
        int pick=1e9;
        if(sum>=coins[index]){
            pick=1+combination(coins,dp,sum-coins[index],index,cnt+1);
        }
        return dp[index][sum]=min(notpick,pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       // return 
        long long res = combination(coins,dp,amount,n-1,0);
        if(res==1e9)return -1;
        return res;
       // return mincnt==INT_MAX?-1:mincnt;
    }
};