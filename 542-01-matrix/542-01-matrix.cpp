class Solution {
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