class Solution {
private:
    long long int dp[25][2][300];
    long long int mod=1e9+7;
    int check(string&num,int msum,int mxsum){
        int sum=0;
        for(auto&it:num){
            sum+=(it-'0');
        }
        if(sum>=msum&&sum<=mxsum)return 1;
        return 0;
    }
    int sub(string&temp,int index,int tight,int sum,int msum,int mxsum){
        if(index==temp.size()){
            if(sum>=msum&&sum<=mxsum)return 1;
            return 0;
        }
        if(dp[index][tight][sum]!=-1)return (dp[index][tight][sum])%mod;
        int high = 9;
        if(tight)high = temp[index]-'0';
        long long int ans = 0;
        for(int i=0;i<=high;i++){
            ans=(long long)((ans)%mod+(sub(temp,index+1,tight&(i==high),sum+i,msum,mxsum))%mod)%mod;
        }
        return dp[index][tight][sum]=ans;
    }
public:
    int count(string num1, string num2, int minsum, int maxsum) {
        memset(dp,-1,sizeof(dp));
        int b = sub(num2,0,1,0,minsum,maxsum);
        memset(dp,-1,sizeof(dp));
        int a = sub(num1,0,1,0,minsum,maxsum);
        int cnt = check(num1,minsum,maxsum);
        return (b-a+cnt+mod)%mod;
    }
};