class Solution {
private:
    int n=0,m=0;
    bool check(int i,int j){
        return i>=0&&j>=0&&i<n&&j<m;
    }
    // void dfs(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&vis,int&cnt){
    //     if(vis[i][j])return;
    //     vis[i][j]=1;
    //     // if(grid[i][j]==1){
    //     //     grid[i][j]=2;
    //     // }
    // }
public:
    int orangesRotting(vector<vector<int>>& grid) {
       n=grid.size();
       m=grid[0].size();
      // int total=0;
      // vector<vector<bool>>vis(n,vector<bool>(m,0));
      // for(int i=0;i<n;i++){
      //     for(int j=0;j<m;j++){
      //         if(grid[i][j]==2&&!vis[i][j]){
      //            int cnt=0;
      //             dfs(grid,i,j,vis,cnt);
      //            total+=cnt;
      //         }
      //     }
      // }
      // for(auto it:grid){
      //     for(auto vt:it){
      //         if(vt==1)return -1;
      //     }
      // }
      //   return total;
        int cnt=0;
        queue<pair<pair<int,int>,int>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    pq.push({{i,j},0});
                }
                if(grid[i][j]==1)++cnt;
            }
        }
        int tm=0;int infect=0;
        while(!pq.empty()){
            int row=pq.front().first.first;
            int col=pq.front().first.second;
            int time=pq.front().second;
            tm=max(tm,time);
            pq.pop();
            vector<int>dx{-1,0,1,0};
            vector<int>dy{0,1,0,-1};
           for(int i=0;i<4;i++){
            if(check(row+dx[i],col+dy[i])&&grid[row+dx[i]][col+dy[i]]==1){
               grid[row+dx[i]][col+dy[i]]=2;
                ++infect;
               pq.push({{row+dx[i],col+dy[i]},time+1});
            }
          }
        }
        if(cnt!=infect)return -1;
        return tm;
    }
};