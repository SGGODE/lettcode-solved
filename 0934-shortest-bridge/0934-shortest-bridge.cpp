// class Solution {
// private:
//     int n,m;
//     bool check(int row,int col){
//         return row>=0&&col>=0&&row<n&&col<m;
//     }
//     void dfs(vector<vector<int>>&grid,int row,int col,vector<vector<bool>>&vis,map<pair<int,int>,int>&mp){
//         vis[row][col]=1;
//         mp[{row,col}]++;
//         if(check(row+1,col)&&!vis[row+1][col]&&grid[row+1][col]==1){
//             dfs(grid,row+1,col,vis,mp);
//         }
//         if(check(row-1,col)&&!vis[row-1][col]&&grid[row-1][col]==1){
//             dfs(grid,row-1,col,vis,mp);
//         }
//         if(check(row,col+1)&&!vis[row][col+1]&&grid[row][col+1]==1){
//             dfs(grid,row,col+1,vis,mp);
//         }
//         if(check(row,col-1)&&!vis[row][col-1]&&grid[row][col-1]==1){
//             dfs(grid,row,col-1,vis,mp);
//         } 
//     }
//    int bfs(vector<vector<int>>&grid,int row,int col,map<pair<int,int>,int>&mp){
//        queue<pair<pair<int,int>,int>>pq;
//        int cnt=0;
//        int mincnt=INT_MAX;
//        pq.push({{row,col},cnt});
//        vector<vector<bool>>vis(n,vector<bool>(m,0));
//        vis[row][col]=1;
//        while(!pq.empty()){
//            int cr=pq.front().first.first;
//            int cc=pq.front().first.second;
//            int cot=pq.front().second;
//            pq.pop();
//            int dx[4]={-1,1,0,0};
//            int dy[4]={0,0,-1,1};
//            for(int i=0;i<4;i++){
//                if(check(cr+dx[i],cc+dy[i])){
//                   if(mp.count({cr+dx[i],cc+dy[i]})){
//                       mincnt=min(mincnt,cot);
//                       //cout<<cr<<" "<<cc<<endl;
//                       continue;
//                   }
//                }
//               // continue;
//            }
//            for(int i=0;i<4;i++){
//                if(check(cr+dx[i],cc+dy[i])&&!vis[cr+dx[i]][cc+dy[i]]&&grid[cr+dx[i]][cc+dy[i]]==0){
//                    vis[cr+dx[i]][cc+dy[i]]=1;
//                    pq.push({{cr+dx[i],cc+dy[i]},cot+1});
//                }
//            }
//        }
//        return mincnt;
//    }
// public:
//     int shortestBridge(vector<vector<int>>& grid) {
//         map<pair<int,int>,int>mp;
//         map<pair<int,int>,int>mx;
//         n=grid.size();
//         m=grid[0].size();
//         int cnt=0;
//         vector<vector<bool>>vis(n,vector<bool>(m,0));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(cnt==0&&grid[i][j]==1){
//                     dfs(grid,i,j,vis,mp);
//                     cnt=1;
//                     continue;
//                 }else if(vis[i][j]==0&&grid[i][j]==1){
//                     dfs(grid,i,j,vis,mx);
//                 }
//             }
//         }
//         int mincnt=INT_MAX;
//         for(auto &it:mp){
//             int cnt=bfs(grid,it.first.first,it.first.second,mx);
//             //cout<<cnt<<endl;
//             mincnt=min(mincnt,cnt);
//         }
//         return mincnt;
//     }
// };
class Solution
{
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    void change(vector<vector<int>> &grid, int x, int y)
    {
        q.push({x, y});
        int n = grid.size();
        int m = grid[0].size();
        grid[x][y] = 2;
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1)
            {
                change(grid, nx, ny);
            }
        }
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        bool f = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    change(grid, i, j);
                    f = true;
                    break;
                }
            }
            if (f)
                break;
        }
        int ans = 0;
        while (q.size())
        {
            int total = q.size();
            ans++;
            while (total--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                    {
                        if (grid[nx][ny] == 1)
                            return ans - 1;
                        else if (grid[nx][ny] == 0)
                        {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
