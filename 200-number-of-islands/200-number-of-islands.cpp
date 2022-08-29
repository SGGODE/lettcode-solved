class Solution {
private:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int src,int des,int n,int m){
        vis[src][des]=1;
        int dx[4]={-1,0,+1,0};
        int dy[4]={0,+1,0,-1};
        for(int i=0;i<4;i++){
           int nr=src+dx[i];
           int ny=des+dy[i];
           if(nr >=0 && ny >=0 && nr < n && ny < m
             && !vis[nr][ny] && grid[nr][ny]=='1')
               dfs(grid,vis,nr,ny,n,m);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
     int n=grid.size();
     int m=grid[0].size();
     vector<vector<int>> vis(n,vector<int>(m,0));
     int cnt=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(!vis[i][j]&&grid[i][j]=='1'){
              cnt++;
              dfs(grid,vis,i,j,n,m);
          }  
        }
     }
      return cnt;
    }
};