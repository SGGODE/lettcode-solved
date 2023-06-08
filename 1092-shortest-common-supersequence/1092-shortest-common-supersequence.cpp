class Solution {
public:
    string shortestCommonSupersequence(string s, string x) {
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
        int row=n;
        int col=m;
        string res;
        while(row>0&&col>0){
            if(s[row-1]==x[col-1]){
                res.push_back(s[row-1]);
                row=row-1;
                col=col-1;
                continue;
            }else if(dp[row][col]==dp[row-1][col]){
                res.push_back(s[row-1]);
                row=row-1;
                continue;
            }else if(dp[row][col]==dp[row][col-1]){
                res.push_back(x[col-1]);
                col=col-1;
            }
        }
         while(row>0){
             res.push_back(s[row-1]);
             --row;
         }
         while(col>0){
             res.push_back(x[col-1]);
             --col;
         }
        reverse(res.begin(),res.end());
        return res;
    }
};