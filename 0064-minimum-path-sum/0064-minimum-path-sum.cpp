class Solution {
private:
   // /* int n=grid.size();
   //      int m=grid[0].size();
   //      vector<vector<int>>dp(n,vector<int>(m,-1));
   //      /*for(int i=0;i<n;i++){
   //          for(int j=0;j<n;i++){
   //              if(i==0 && j==0)
   //                  dp[i][j]==1;
   //              else{
   //              int up=0,down=0;
   //              if(i>1){
   //                  up=grid[i][j]+dp[i][i-1];
   //              }
   //              if(j>1){
   //                  down=grid[i][j]+dp[i-1][j];
   //              }
   //              dp[i][j]=min(up,down);
   //           }
   //          }
   //      }
   //      return dp[n-1][m-1];*/
   //     // return get(grid,dp,n,m,0,0);
   //     return get(grid,dp,n,m,0,0); 
   // int get(vector<vector<int>>&grid,vector<vector<int>>&dp,int n,int m,int s,int e){
   //      if(s==n-1 && e==m-1){
   //          return grid[s][e];
   //      }
   //      if(s>=n||e>=m){
   //          return 1000;
   //      }
   //      if(dp[s][e]!=-1){
   //          return dp[s][e];
   //      }
   //      int left=grid[s][e]+get(grid,dp,n,m,s+1,e);
   //      int right=grid[s][e]+get(grid,dp,n,m,s,e+1);
   //      return dp[s][e]=min(left,right);
   //  }*/
   //  int get(vector<vector<int>>&grid,vector<vector<int>>&dp,int n,int m,int s,int e){
   //      if(s==n-1 && e==m-1){
   //          return grid[s][e];
   //      }
   //      if(s>=n||e>=m){
   //          return 1000;
   //      }
   //      if(dp[s][e]!=-1){
   //          return dp[s][e];
   //      }
   //      //int maxi=INT_MAX;
   //     int left=grid[s][e]+get(grid,dp,n,m,s+1,e);
   //     int right=grid[s][e]+get(grid,dp,n,m,s,e+1);
   //      dp[s][e]=min(left,right);
   //      return dp[s][e];
   //  }
public:
    int pathsum(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j,int n,int m){
        if(i==n-1&&j==m-1){
            return grid[i][j];
        }
        if(i>=n||j>=m)return 1000;
        if(dp[i][j]!=-1)return dp[i][j];
        int left=grid[i][j]+pathsum(grid,dp,i+1,j,n,m);
        int right=grid[i][j]+pathsum(grid,dp,i,j+1,n,m);
        return dp[i][j]=min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return pathsum(grid,dp,0,0,n,m);
    }
};