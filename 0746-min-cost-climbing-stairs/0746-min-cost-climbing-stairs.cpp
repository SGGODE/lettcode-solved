class Solution {
private:
    int fun(vector<int>&cost,int index,vector<int>&dp){
        if(index==cost.size()+1||index==cost.size()){
            return 0;
        }
        if(index==cost.size()-1){
            return cost[index];
        }
        if(dp[index]!=-1)return dp[index];
        int one=cost[index]+fun(cost,index+1,dp);
        int two=cost[index]+fun(cost,index+2,dp);
        return dp[index]=min(one,two);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(fun(cost,0,dp),fun(cost,1,dp));
    }
};