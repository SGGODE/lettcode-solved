class Solution {
private:
    bool check(int n,int m,int row,int col){
        return row>=0&&col>=0&&row<n&&col<m;
    }
    int sub(vector<vector<int>>&grid,int k){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        queue<pair<pair<int,int>,pair<int,int>>>pq;
        pq.push({{0,0},{0,k}});
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        while(!pq.empty()){
            int row = pq.front().first.first;
            int col = pq.front().first.second;
            int distance = pq.front().second.first;
            int magic = pq.front().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                if(check(n,m,row+dx[i],col+dy[i])&&distance+1<dist[row+dx[i]][col+dy[i]]&&grid[row+dx[i]][col+dy[i]]==0){
                   dist[row+dx[i]][col+dy[i]]=distance+1;
                   pq.push({{row+dx[i],col+dy[i]},{distance+1,magic}});
                }else if(check(n,m,row+dx[i],col+dy[i])&&distance+1<dist[row+dx[i]][col+dy[i]]&&grid[row+dx[i]][col+dy[i]]==1&&magic!=0){
                   dist[row+dx[i]][col+dy[i]]=distance+1;
                   pq.push({{row+dx[i],col+dy[i]},{distance+1,magic-1}});
                }
            }
        }
        return dist[n-1][m-1];
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // int res = sub(grid,k);
        // return res>=1e9?-1:res;
          int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,-1));
        queue<vector<int>> q;
        q.push({0,0,0,k});
        while(!q.empty()){
            vector<int> t = q.front();
            q.pop();
            int i=t[0];
            int j = t[1];
            
            if(i<0 || i>=m || j<0 || j>=n) continue;
            
            if(i==m-1 && j==n-1) return t[2];
            
         if(grid[i][j]==1){
             if(t[3]>0){
                 t[3]--;
             }
             else continue;
         }
        if(vis[i][j]!= -1 && vis[i][j] >=t[3])  continue;
        
        vis[i][j] = t[3];
        
        q.push({i+1,j,t[2]+1,t[3]});   // down
        q.push({i-1,j,t[2]+1,t[3]});   // up
        q.push({i,j+1,t[2]+1,t[3]});  // right
        q.push({i,j-1,t[2]+1,t[3]});  // left
         
    }
    return -1; 
    }
};