class Solution {
private:
    int dp[101][101];
    int cost(string&s,int start,int end){
        if(start>=end)return 0;
        int ans = 0;
        if(s[start]!=s[end])ans++;
        return ans+cost(s,start+1,end-1);
    }
    int sub(string&s,int index, int k,int n){
        if(index==n){
            return k==-1?0:1e9;
        }
        if(k==0)return cost(s,index,n-1);
        if(dp[index][k]!=-1)return dp[index][k];
        int ans = 1e9;
        for(int i=index;i<s.size();i++){
            ans = min(ans,sub(s,i+1,k-1,n)+cost(s,index,i));
        }
        return dp[index][k]=ans;
    }
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return sub(s,0,k-1,n);
    }
};