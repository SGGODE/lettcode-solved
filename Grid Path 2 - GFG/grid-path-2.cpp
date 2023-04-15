//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    int mod=1e9+7;
    int doitforme(vector<vector<int>>&dp,vector<vector<int>>&vis,int i,int j){
        if(i<0||j<0)return 0;
        if(vis[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=(doitforme(dp,vis,i-1,j))%mod+(doitforme(dp,vis,i,j-1))%mod;
    }
  public:
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        // vector<vector<bool>>vis(n,vector<bool>(m,0));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]==1)vis[i][j]=1;
        //     }
        // }
        if(n==1&&m==1&&grid[n-1][m-1]==1)return 0;
        if(n==1&&m==1&&grid[n-1][m-1]==0)return 1;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       // dp[0][0]
        dp[0][0]=1;
        dp[0][1]=1;
        dp[1][0]=1;
        if(n<1&&m<1)return dp[n][m];
        doitforme(dp,grid,n-1,m-1);
        if(dp[n-1][m-1]==-1)return 0;
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends