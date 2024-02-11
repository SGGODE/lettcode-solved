class Solution {
private:
   int n,m;
   int dp[71][71][71]; 
   int sub(vector<vector<int>>& grid,int row,int col1,int col2){
        if(row<0||col1<0||col2<0||col1>=m||col2>=m){
            return -1e8;
        }
        if(row==n-1){
            if(col1==col2)return grid[row][col1];
            return grid[row][col1]+grid[row][col2];
        }
        if(dp[row][col1][col2]!=-1)return dp[row][col1][col2];
        int ans = -1e9;
        if(col1==col2){
            ans = max(ans,grid[row][col1]+sub(grid,row+1,col1-1,col2-1));
            ans = max(ans,grid[row][col1]+sub(grid,row+1,col1+1,col2+1));
            ans = max(ans,grid[row][col1]+sub(grid,row+1,col1,col2));
        }else{
            ans = max(ans,(grid[row][col1]+grid[row][col2])+sub(grid,row+1,col1-1,col2-1));
            ans = max(ans,(grid[row][col1]+grid[row][col2])+sub(grid,row+1,col1-1,col2));
            ans = max(ans,(grid[row][col1]+grid[row][col2])+sub(grid,row+1,col1-1,col2+1));
            ans = max(ans,(grid[row][col1]+grid[row][col2])+sub(grid,row+1,col1,col2));
            ans = max(ans,(grid[row][col1]+grid[row][col2])+sub(grid,row+1,col1,col2-1));
            ans = max(ans,(grid[row][col1]+grid[row][col2])+sub(grid,row+1,col1,col2+1));
            ans = max(ans,(grid[row][col1]+grid[row][col2])+sub(grid,row+1,col1+1,col2-1));
            ans = max(ans,(grid[row][col1]+grid[row][col2])+sub(grid,row+1,col1+1,col2));
            ans = max(ans,(grid[row][col1]+grid[row][col2])+sub(grid,row+1,col1+1,col2+1));
        }
        return dp[row][col1][col2]=ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
       n = grid.size();
       m = grid[0].size();
       memset(dp,-1,sizeof(dp));
       return sub(grid,0,0,m-1);
    }
};