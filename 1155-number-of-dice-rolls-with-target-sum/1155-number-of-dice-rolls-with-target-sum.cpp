class Solution {
private:
    int mod = 1e9+7;
    int dp[31][1001];
    int sub(int n,int k,int target){
        if(n==0&&target==0)return 1;
        if(n==0||target==0)return 0;
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int ans = 0;
        for(int i=1;i<=k;i++){
            if(i<=target){
                ans = (ans + sub(n-1,k,target-i))%mod;
            }else break;
        }
        return dp[n][target]=ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        //cout<<1<<endl;
        return sub(n,k,target);
    }
};