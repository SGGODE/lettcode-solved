class Solution {
// private:
//     int n;
//     bool check(int row,int col){
//         return row>=0&&col<n&&row<n&&col>=0;
//     }
//     bool path(vector<vector<int>>grid,vector<vector<int>>&dist,int row,int col,int requireddistance){
//         int ans = dist[row][col];
//         if(ans<requireddistance)return 0;
//         queue<pair<pair<int,int>,int>>pq;
//         pq.push({{row,col},dist[row][col]});
//         while(!pq.empty()){
//             int r = pq.front().first.first;
//             int c = pq.front().first.second;
//             grid[r][c]=-1;
//             int val = pq.front().second;
//             pq.pop();
//             if(r==n-1&&c==n-1)return 1;
//             int dx[4]={0,0,1,-1};
//             int dy[4]={1,-1,0,0};
//             for(int i=0;i<4;i++){
//                 if(check(r+dx[i],c+dy[i])&&grid[r+dx[i]][c+dy[i]]!=-1&&dist[r+dx[i]][c+dy[i]]>=requireddistance){
//                     pq.push({{r+dx[i],c+dy[i]},min(val,dist[r+dx[i]][c+dy[i]])});
//                 }
//             }
//          }
//         return 0;
//     }
// public:
//     int maximumSafenessFactor(vector<vector<int>>& grid) {
//         n = grid.size();
//        // memset(dp,-1,sizeof(dp));
//         int result = 0;
//         set<pair<int,int>>st;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1)st.insert({i,j});
//             }
//         }
//         if(grid[0][0]==1||grid[n-1][n-1]==1)return 0;
//         vector<vector<int>>dist(n,vector<int>(n,1e9));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 int ans = 1e9;
//                 for(auto&it:st){
//                    ans = min(ans,abs(it.first-i)+abs(it.second-j));
//                 }
//                 dist[i][j]=ans;
//                 result=max(result,ans);
//             }
//         }
//         for(int i=result;i>=0;i--){
//             if(path(grid,dist,0,0,i)){
//                 return i;
//             }
//         }
//         return 0;
//     }
public:
    int maximumSafenessFactor(vector<vector<int>>& g) {
    queue<array<int, 2>> q;
    int dir[5] = {1, 0, -1, 0, 1}, n = g.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (g[i][j])
                q.push({i, j});
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (min(x, y) >= 0 && max(x, y) < n && g[x][y] == 0) {
                g[x][y] = g[i][j] + 1;
                q.push({x, y});
            }
        }
    }
    priority_queue<array<int, 3>> pq;
    pq.push({g[0][0], 0, 0});
    while (pq.top()[1] < n - 1 || pq.top()[2] < n - 1) {
        auto [sf, i, j] = pq.top(); pq.pop();
        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (min(x, y) >= 0 && max(x, y) < n && g[x][y] > 0) {
                pq.push({min(sf, g[x][y]), x, y});
                g[x][y] *= -1; 
            }
        }
    }
    return pq.top()[0] - 1;
}
};