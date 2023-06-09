class Solution {
public:
    int minDistance(string s, string x) {
       // string x=s;
        //reverse(x.begin(),x.end());
        int n=s.size();
        int m=x.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==x[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return abs((n+m)-(2*dp[n][m]));
   // }
    }
};