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
int fro(vector<vector<int>>&dp,vector<vector<int>>&grid,int n,int m){
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
             if(i>=0 && j>=0 && grid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
             if(i==0 && j==0){
                 dp[i][j]=1;
                 continue;
             }
             int left=0,right=0;
             if(i>0)
                left=dp[i-1][j];
             if(j>0)
                right=dp[i][j-1];
              dp[i][j]=left+right;
            }
         }
        return dp[n-1][m-1];
}
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fro(dp,obstacleGrid,n,m);
        //return get(dp,obstacleGrid,n-1,m-1);
    }
};