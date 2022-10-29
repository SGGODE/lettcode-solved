class Solution {
private:
    int count(vector<int>&dp,int n){
        if(n<=1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int left=count(dp,n-1);
        int right=count(dp,n-2);
        return dp[n]=left+right;
    }
public:
    int climbStairs(int n) {
      vector<int>dp(n+1,-1);
      return count(dp,n);
    }
};