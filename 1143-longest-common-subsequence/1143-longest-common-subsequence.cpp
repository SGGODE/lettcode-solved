class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        int mi=min(n,m);
        int mx=max(n,m);
        vector<vector<int>>dp(mi+1,vector<int>(mx+1,0));
        bool flag=0;
        if(mx==n){
            flag=1;
        }
        for(int i=1;i<=mi;i++){
            for(int j=1;j<=mx;j++){
                if(flag){
                    if(s1[j-1]==s2[i-1]){
                        dp[i][j]=dp[i-1][j-1]+1;
                    }else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }else{
                      if(s2[j-1]==s1[i-1]){
                        dp[i][j]=dp[i-1][j-1]+1;
                    }else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        // for(auto it:dp){
        //     for(auto vt:it)cout<<vt<<" ";
        //     cout<<endl;
        // }
        if(flag)return dp[m][n];
       // return 
       //return 3;
       // return dp[n-][m];
        return dp[n][m];
    }
};