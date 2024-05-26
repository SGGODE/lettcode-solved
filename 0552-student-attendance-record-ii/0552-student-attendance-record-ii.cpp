class Solution {
private:
    int mod = 1e9+7;
    int dp[100001][2][3];
    int sub(int n,int index,int abs,int late){
        if(index==n)return 1;
        if(dp[index][abs][late]!=-1)return dp[index][abs][late]%mod;
        int ans = 0;
        int val = 0;
        ans = (ans + sub(n,index+1,abs,val))%mod;
        if(abs!=0){
            --abs;
            ans = (ans + sub(n,index+1,abs,val))%mod;
            ++abs;
        }
        if(late<2){
            ++late;
            ans = (ans + sub(n,index+1,abs,late))%mod;
            --late;
        }
        return dp[index][abs][late]=ans%mod;
    }
public:
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        int abs=1,late=0;
        return sub(n,0,abs,late);
    }
};