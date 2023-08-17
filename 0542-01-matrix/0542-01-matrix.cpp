class Solution {
// private:
//     bool check(int row,int col,int n,int m){
//         return row>=0&&col>=0&&row<n&&col<m;
//     }
//     int dist(vector<vector<int>>&mat,int row,int col,int n,int m){
//         int dx[4]={0,0,-1,1};
//         int dy[4]={1,-1,0,0};
//         vector<vector<bool>>vis(n,vector<bool>(m,0));
//         queue<pair<pair<int,int>,int>>pq;
//         vis[row][col]=1;
//         pq.push({{row,col},0});
//         int total=INT_MAX;
//         while(!pq.empty()){
//             int crow = pq.front().first.first;
//             int ccol = pq.front().first.second;
//             int time = pq.front().second;
//            // cout<<time<<endl;
//             pq.pop();
//             if(mat[crow][ccol]==0){
//                // cout<<"1"<<endl;
//                 total=min(total,time);
//                 continue;
//             }
//             for(int i=0;i<4;i++){
//                 if(check(crow+dx[i],ccol+dy[i],n,m)&&res[crow+dx[i]][ccol+dy[i]]>time+1){
//                    // vis[crow+dx[i]][ccol+dy[i]]=1;
//                    // cout<<"Yes"<<endl;
//                     res[crow+dx[i]][ccol+dy[i]]>time+1
//                     pq.push({{crow+dx[i],ccol+dy[i]},time+1});
//                 }
//             }
//         }
//       //  cout<<total<<endl;
//         return total;
//     }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
     int n=mat.size();
     int m=mat[0].size();
     vector<vector<int>> vis(n,vector<int>(m,0));
     vector<vector<int>> dist(n,vector<int>(m,0));   
     queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(mat[i][j]==0){
                 q.push({{i,j},0});
                 vis[i][j]=1;
             }
             else{
                 vis[i][j]=0;
             }
         }
      }
      int dx[4]={-1,0,+1,0};
      int dy[4]={0,+1,0,-1};
      while(!q.empty()){
         int row=q.front().first.first;
         int col=q.front().first.second;
         int dis=q.front().second;
         dist[row][col]=dis;
         q.pop();
         for(int i=0;i<4;i++){
             int nr=row+dx[i];
             int nc=col+dy[i];
             if(nr >=0 && nc >=0 && nr < n && nc < m
             && !vis[nr][nc]){
                 vis[nr][nc]=1;
                 q.push({{nr,nc},dis+1});
             }
         }
      }
      return dist;
    }
};