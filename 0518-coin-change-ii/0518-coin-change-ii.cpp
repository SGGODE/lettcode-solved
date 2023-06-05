class Solution {
private:
    int combinations(vector<int>&coins,vector<vector<int>>&dp,int sum,int index){
        if(sum==0)return 1;
        if(index==0){
            if(sum%coins[index]==0)return 1;
            return 0;
        }
       // cout<<index<<endl;
        if(dp[index][sum]!=-1)return dp[index][sum];
        int notpick=0+combinations(coins,dp,sum,index-1);
        int pick=0;
        if(sum>=coins[index]){
            pick=combinations(coins,dp,sum-coins[index],index);
        }
        return dp[index][sum]=pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       return combinations(coins,dp,amount,n-1);
        // for(auto &it:dp){
        //     for(auto &vt:it)cout<<vt<<" ";
        //     cout<<endl;
        // }
        // return dp[0][0];
    }
};