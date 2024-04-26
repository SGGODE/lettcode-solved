class Solution {
private:
   vector<vector<int>>dp;
   int sub(vector<vector<int>>&grid,int row,int col){
       if(row==grid.size())return 0;
       if(dp[row][col+1]!=-1)return dp[row][col+1];
       int ans = 1e9;
       for(int i=0;i<grid[0].size();i++){
          if(col==-1)ans = min(ans,grid[row][i]+sub(grid,row+1,i));
          else if(i!=col)ans = min(ans,grid[row][i]+sub(grid,row+1,i));
       }
       return dp[row][col+1]=ans;
   }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n,vector<int>(m+1,-1));
        return sub(grid,0,-1);
    }
};