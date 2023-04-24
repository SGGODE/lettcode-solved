//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int x, int y)
    {
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        //sub(x-1,y-1,s1,s2,dp);
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
               }//else{
                //     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                // }
            }
        }
        int maxmath=INT_MIN;
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                maxmath=max(maxmath,dp[i][j]);
            }
        }
        return maxmath;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends