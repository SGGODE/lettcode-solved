//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    // int pathsum(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j){
    //     if(i==0&&j==0){
    //         return grid[i][j];
    //     }
    //     if(i<0||j<0)return INT_MAX;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int up=pathsum(grid,dp,i-1,j);
    //     int side=pathsum(grid,dp,i,j-1);
    //     int diagonal=pathsum(grid,dp,i-1,j-1);
    //     return dp[i][j]=grid[i][j]+min(side,min(up,diagonal));
    // }
   
public:
   int n;
    bool check(int row,int col){
        return row>=0&&col>=0&&row<n&&col<n;
    }
    int maximumPath(int N, vector<vector<int>>grid)
    {
        // code here
        n=N;
        if(n==1)return grid[0][0];
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<1;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=grid[i][j];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int ans=grid[i][j];
                if(check(i-1,j))ans=max(ans,grid[i][j]+dp[i-1][j]);
                if(check(i-1,j-1))ans=max(ans,grid[i][j]+dp[i-1][j-1]);
                if(check(i-1,j+1))ans=max(ans,grid[i][j]+dp[i-1][j+1]);
                dp[i][j]=ans;
            }
        }
        return *max_element(dp[n-1].begin(),dp[n-1].end());
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends