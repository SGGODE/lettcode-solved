//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
   int n,m;
   bool check(int i,int j){
       return i>=0&&j>=0&&i<n&&j<m;
   }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
         n=grid.size();
         m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        queue<pair<int,int>>pq;
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ++cnt;
                }
                if(grid[i][j]==1&&(i==0||j==0||j==m-1||i==n-1)){
                    pq.push({i,j});
                    vis[i][j]=1;
                    --cnt;
                }
            }
        }
        while(!pq.empty()){
            int row=pq.front().first;
            int col=pq.front().second;
            int dx[4]={1,0,-1,0};
            int dy[4]={0,1,0,-1};
            pq.pop();
            for(int i=0;i<4;i++){
                if(check(row+dx[i],col+dy[i])&&!vis[row+dx[i]][col+dy[i]]&&grid[row+dx[i]][col+dy[i]]==1){
                    vis[row+dx[i]][col+dy[i]]=1;
                    pq.push({row+dx[i],col+dy[i]});
                    //if(cnt>1)
                    --cnt;
                }
            }
        }
        if(cnt<0)return 0;
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends