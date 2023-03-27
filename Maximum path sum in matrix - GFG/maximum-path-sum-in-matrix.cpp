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
    int n,m;
    bool check(int i,int j){
        return i>=0&&j>=0&&i<n&&j<m;
    }
    void maxpossible(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j){
        int max_val=INT_MIN;
        if(check(i-1,j))max_val=max(max_val,grid[i][j]+dp[i-1][j]);
        if(check(i-1,j+1))max_val=max(max_val,grid[i][j]+dp[i-1][j+1]);
        if(check(i-1,j-1))max_val=max(max_val,grid[i][j]+dp[i-1][j-1]);
        dp[i][j]=max_val;
    }
public:
    int maximumPath(int N, vector<vector<int>>grid)
    {
        // code here
         n=grid.size();
         m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<1;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=grid[i][j];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                maxpossible(grid,dp,i,j);
            }
        }
        int max_sum=INT_MIN;
        for(int i=n-1;i>n-2;i--){
            for(int j=0;j<m;j++){
                max_sum=max(max_sum,dp[i][j]);
            }
        }
        return max_sum;
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