class Solution {
private:
    int n,m;
    bool check(int row,int col){
        return row>=0&&col>=0&&row<n&&col<m;
    }
    int bfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int row,int col){
        queue<pair<int,int>>pq;
        pq.push({row,col});
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        vis[row][col]=1;
        int cnt=1;
        while(!pq.empty()){
           int crow=pq.front().first;
           int ccol=pq.front().second;
           pq.pop();
           for(int i=0;i<4;i++){
               if(check(crow+dx[i],ccol+dy[i])&&grid[crow+dx[i]][ccol+dy[i]]==1&&!vis[crow+dx[i]][ccol+dy[i]]){
                   vis[crow+dx[i]][ccol+dy[i]]=1;
                   ++cnt;
                   pq.push({crow+dx[i],ccol+dy[i]});
               }
           }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
         int res=0;
         vector<vector<bool>>vis(n,vector<bool>(m,0));
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(!vis[i][j]&&grid[i][j]==1){
                    int len = bfs(grid,vis,i,j);
                    res = max(res,len);
                 }
             }
         }
        return res;
    }
};