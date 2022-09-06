class Solution {
private:
    int get(vector<vector<int>>&grid,vector<vector<int>>&dp,int n,int m,int s,int e){
        if(s==n-1 && e==m-1){
            return grid[s][e];
        }
        if(s>=n||e>=m){
            return 1000;
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        int left=grid[s][e]+get(grid,dp,n,m,s+1,e);
        int right=grid[s][e]+get(grid,dp,n,m,s,e+1);
        return dp[s][e]=min(left,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return get(grid,dp,n,m,0,0);
    }
};