class Solution {
private:
    int n,m;
    bool check(int row , int col){
        return row >= 0 && col >= 0 && row < n && col < m;
    }
    void bfs(vector<vector<int>>&grid , vector<vector<bool>>&vis , vector<pair<int,int>>&dp , int row , int col){
         vis[row][col]=1;
         queue<pair<int,int>>pq;
         pq.push({row,col});
         int dx[4] = {0,0,1,-1};
         int dy[4] = {1,-1,0,0};
         while(!pq.empty()){
             int r = pq.front().first;
             int c = pq.front().second;
             dp.push_back({r,c});
             pq.pop();
             for(int i = 0; i < 4 ; i++){
                 if(check(r+dx[i],c+dy[i])&&!vis[r+dx[i]][c+dy[i]]&&grid[r+dx[i]][c+dy[i]]){
                     vis[r+dx[i]][c+dy[i]] = 1;
                     pq.push({r+dx[i],c+dy[i]});
                 }
             }
         }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        map<vector<pair<int,int>>,int>mp;
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]&&grid2[i][j]){
                    vector<pair<int,int>>dp;
                    bfs(grid2,vis,dp,i,j);
                    mp[dp]++;
                }
            }
        }
        for(auto&it:mp){
            vector<pair<int,int>>res = it.first;
            bool flag = 1;
            for(auto&vt:res){
                if(!grid1[vt.first][vt.second]){
                    flag = 0;
                    break;
                }
            }
            if(flag)++count;
        }
        return count;
    }
};