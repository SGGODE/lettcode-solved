class Solution {
private:
    int sub(vector<vector<int>>&dp,string s,string t,int i,int j){
        if(j<0)return 1;
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int pick=0;
        int notpick=0;
        if(s[i]==t[j]){
            pick=sub(dp,s,t,i-1,j-1)+sub(dp,s,t,i-1,j);
        }
        else notpick=sub(dp,s,t,i-1,j);
        return dp[i][j]=pick+notpick;
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return sub(dp,s,t,n-1,m-1);
    }
};