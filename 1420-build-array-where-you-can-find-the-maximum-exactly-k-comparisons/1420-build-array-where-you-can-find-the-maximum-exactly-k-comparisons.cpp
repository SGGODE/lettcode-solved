class Solution {
private:
    int dp[51][101][51];
    int mod = 1e9+7;
    int sub(int index,int large,int uplimit,int maxint,int ops,int k){
        if(index==uplimit&&ops==k)return 1;
        if(index==uplimit)return 0;
        if(dp[index][large][ops]!=-1)return dp[index][large][ops];
        int ans = 0;
        for(int i=1;i<=maxint;i++){
            if(large<i){
                ans = (ans + sub(index+1,i,uplimit,maxint,ops+1,k))%mod;
            }else{
                ans = (ans + sub(index+1,large,uplimit,maxint,ops,k))%mod;
            }
        }
        return dp[index][large][ops] = ans%mod;
    }
public:
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return sub(0,0,n,m,0,k);
    }
};