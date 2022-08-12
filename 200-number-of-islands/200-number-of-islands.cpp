class Solution {
private:
  void dfs(int row,int col,vector<vector<char>>& grid, vector<vector<int>>&vis){
      vis[row][col]=1; 
      int n=grid.size();
      int m=grid[0].size();
       int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
             int nr=row+dx[i];
             int nc=col+dy[i];
              if(nr>=0 && nc >=0 && nr<n && nc <m && grid[nr][nc]=='1' && !vis[nr][nc]){
                  dfs(nr,nc,grid,vis); 
              }
      }
  }
public:
    int numIslands(vector<vector<char>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      int cnt=0;
      vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};