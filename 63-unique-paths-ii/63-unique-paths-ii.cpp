class Solution {
private:
    int get(vector<vector<int>>&dp,vector<vector<int>>&grid,int n,int m){
    if(n>=0 &&m>=0 && grid[n][m]==1)
        return 0;
    if(n==0 && m==0){
        return 1;
    }
    if(n<0 || m<0)
        return 0;
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    int left=get(dp,grid,n-1,m);
    int right=get(dp,grid,n,m-1);
    return dp[n][m]=left+right;
}
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return get(dp,obstacleGrid,n-1,m-1);
    }
};