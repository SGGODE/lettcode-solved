class Solution {
private:
    int n,m;
    bool check(int row,int col){
        return row>=0&&col>=0&&row<n&&col<m;
    }
    bool boundary(int row,int col){
        return (row==0||col==0||row==n-1||col==m-1);
    }
    void dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int row,int col){
        if(vis[row][col])return;
        vis[row][col]=1;
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        for(int i=0;i<4;i++){
            if(check(row+dx[i],col+dy[i])&&!vis[row+dx[i]][col+dy[i]]&&grid[row+dx[i]][col+dy[i]]==0){
                dfs(grid,vis,row+dx[i],col+dy[i]);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid){
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(boundary(i,j)&&grid[i][j]==0){
                    dfs(grid,vis,i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0&&!vis[i][j]){
                    ++cnt;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};