//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string s) {
        //code here
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        string s1=s;
        reverse(s1.begin(),s1.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
               if(s[i-1]==s1[j-1]){
                   dp[i][j]=dp[i-1][j-1]+1;
               }else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
            }
        }
       return dp[n][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends