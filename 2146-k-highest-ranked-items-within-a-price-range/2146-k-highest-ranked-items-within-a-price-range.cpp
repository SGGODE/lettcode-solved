class Solution {
private:
    bool check(int row,int col,int n,int m){
     return row>=0&&col>=0&&row<n&&col<m;
    }
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        queue<pair<pair<int,int>,int>>pq;
        pq.push({{start[0],start[1]},0});
        int dx[4]={-1,0,+1,0};
        int dy[4]={0,+1,0,-1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        dp[start[0]][start[1]]=0;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        vis[start[0]][start[1]]=1;
        priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>>px;
        if(grid[start[0]][start[1]]>=pricing[0]&&grid[start[0]][start[1]]<=pricing[1]){
            px.push({{0,grid[start[0]][start[1]]},{start[0],start[1]}});
        }
        while(!pq.empty()){
            int row = pq.front().first.first;
            int col = pq.front().first.second;
            int cost = pq.front().second;
            pq.pop();
            for(int i=0;i<4;i++){
                if(check(row+dx[i],col+dy[i],n,m)&&grid[row+dx[i]][col+dy[i]]>1&&dp[row+dx[i]][col+dy[i]]>cost+1){
                    dp[row+dx[i]][col+dy[i]]=cost+1;
                    if(grid[row+dx[i]][col+dy[i]]>=pricing[0]&&grid[row+dx[i]][col+dy[i]]<=pricing[1]){
                        px.push({{cost+1,grid[row+dx[i]][col+dy[i]]},{row+dx[i],col+dy[i]}});
                    }
                    pq.push({{row+dx[i],col+dy[i]},cost+1});
                }
                if(check(row+dx[i],col+dy[i],n,m)&&grid[row+dx[i]][col+dy[i]]==1&&!vis[row+dx[i]][col+dy[i]]){
                    vis[row+dx[i]][col+dy[i]]=1;
                    pq.push({{row+dx[i],col+dy[i]},cost+1});
                }
            }
        }
        vector<vector<int>>res;
        while(!px.empty()&&k!=0){
            --k;
            res.push_back({px.top().second.first,px.top().second.second});
            px.pop();
        }
        return res;
    }
};