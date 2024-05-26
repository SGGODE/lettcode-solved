class Solution {
private:
    int mod = 1e9+7;
    int dp[100001][2][3];
    //vector<vector<vector<int>>>dp;
    int sub(int n,int abs,int late){
        if(n==0)return 1;
        if(dp[n][abs][late]!=-1)return dp[n][abs][late]%mod;
        int ans = 0;
        int val = 0;
        ans = (ans + sub(n-1,abs,val))%mod;
        if(abs!=0){
            --abs;
            ans = (ans + sub(n-1,abs,val))%mod;
            ++abs;
        }
        if(late<2){
            ++late;
            ans = (ans + sub(n-1,abs,late))%mod;
            --late;
        }
        return dp[n][abs][late]=ans%mod;
    }
public:
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
       // dp.resize(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        int abs=1,late=0;
        return sub(n,abs,late);
    }
};
