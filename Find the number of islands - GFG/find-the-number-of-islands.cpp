//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
 int n,m;
   bool check(int row,int col){
       return row>=0&&col>=0&&row<n&&col<m;
   }
   void dfs(vector<vector<char>>& grid,vector<vector<bool>>&vis,int row,int col){
       if(vis[row][col])return;
       vis[row][col]=1;
      int dx[8]={0,-1,0,1,-1,1,1,-1};
      int dy[8]={-1,0,1,0,-1,-1,1,1};
      for(int i=0;i<8;i++){
          if(check(row+dx[i],col+dy[i])&&!vis[row+dx[i]][col+dy[i]]&&grid[row+dx[i]][col+dy[i]]=='1'){
              dfs(grid,vis,row+dx[i],col+dy[i]);
          }
      }
   }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
       n=grid.size();
       m=grid[0].size();
      queue<pair<int,int>>pq;
      int cnt=0;
      vector<vector<bool>>vis(n,vector<bool>(m,0));
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(grid[i][j]=='1'&&!vis[i][j]){
                  ++cnt;
                 dfs(grid,vis,i,j);
              }
          }
      }
      return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends