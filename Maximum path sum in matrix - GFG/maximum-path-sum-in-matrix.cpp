//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   bool check(int row,int col,int n){
       return row>=0&&col>=0&&row<n&&col<n;
   }
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<1;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=Matrix[i][j];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int x=-1e9,y=-1e9,z=-1e9;
                if(check(i-1,j,n))x=dp[i-1][j];
                if(check(i-1,j-1,n))y=dp[i-1][j-1];
                if(check(i-1,j+1,n))z=dp[i-1][j+1];
                dp[i][j]=max(x,max(y,z));
                dp[i][j]+=Matrix[i][j];
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