class Solution {
private:
    int n,m;
    bool check(int row,int col){
        return row>=0&&col>=0&&row<n&&col<m;
    }
    int mod=1e9+7;
    int sub(vector<vector<int>>&grid,vector<vector<int>>&dp,int row,int col){
        int up=0,low=0,left=0,right=0;
        if(dp[row][col]!=-1)return dp[row][col];
        if(check(row-1,col)&&grid[row-1][col]>grid[row][col]){
            up=1+sub(grid,dp,row-1,col);
        }
        if(check(row+1,col)&&grid[row+1][col]>grid[row][col]){
            low=1+sub(grid,dp,row+1,col);
        }
        if(check(row,col+1)&&grid[row][col+1]>grid[row][col]){
            left=1+sub(grid,dp,row,col+1);
        }
        if(check(row,col-1)&&grid[row][col-1]>grid[row][col]){
            right=1+sub(grid,dp,row,col-1);
        }
        return dp[row][col]=(up+low+right+left)%mod;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
      n=grid.size();
      m=grid[0].size();
      int sum=0;
      vector<vector<int>>dp(n,vector<int>(m,-1));
      for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
              sub(grid,dp,i,j);
         }
      }
        for(auto &it:dp){
            for(auto &vt:it)sum=(sum+vt)%mod;
        }
        return (sum+(n*m))%mod;
    }
};