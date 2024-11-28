// class Solution {
// private:
//     int n,m;
//     bool check(int r,int c){
//         return r >= 0 && c >= 0 
//                && r < n && c < m;
//     }
//     int sub(vector<vector<int>> & grid ,vector<vector<bool>> & vis, int r , int c){
//         if(r == n-1 && c == m-1)return 0;
//         vis[r][c] = 1;
//         int ans = 1e9;
//         int dx[4] = {0 , 0 , -1 , 1};
//         int dy[4] = {-1 , 1 , 0 , 0};
//         for(int i = 0; i < 4; i++){
//             if(check(r + dx[i] , c + dy[i])&& !vis[r + dx[i]][c + dy[i]]){
//                 if(grid[r + dx[i]][c + dy[i]]){
//                     ans = min(ans , 1 + sub(grid , vis , r + dx[i] , c + dy[i]));
//                 }else{
//                     ans = min(ans , sub(grid , vis , r + dx[i] , c + dy[i]));
//                 }
//             }
//         }
//         vis[r][c] = 0;
//         return ans;
//     }
// public:
//     int minimumObstacles(vector<vector<int>>& grid) {
//         n = grid.size() , m = grid[0].size();
//         vector<vector<bool>>vis(n,vector<bool>(m,0));
//         return sub(grid,vis,0,0);
//     }
// };
class Solution {
private:
    int n,m;
    bool check(int row,int col){
        return row>=0&&row<n&&col>=0&&col<m;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        int mremove = 1e9;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        vis[0][0]=1;
        while(!pq.empty()){
            int remove = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(remove>mremove)continue;
            if(row==n-1&&col==m-1&&remove<mremove){
                mremove = remove;
            }
            for(int i=0;i<4;i++){
                if(check(row+dx[i],col+dy[i])&&!vis[row+dx[i]][col+dy[i]]){
                   vis[row+dx[i]][col+dy[i]]=1;
                   if(grid[row+dx[i]][col+dy[i]]==0)pq.push({remove,{row+dx[i],col+dy[i]}});
                   else pq.push({remove+1,{row+dx[i],col+dy[i]}});
                }
            }
        }
        return mremove;
    }
};