class Solution {
private:
    int dp[2001];
    bool check(string&s,int start,int end){
        while(start<end){
            if(s[start]!=s[end])return 0;
            ++start;--end;
        }
        return 1;
    }
    int sub(string&s,int index,int n){
        if(index==n)return 0;
        if(check(s,index,n-1))return 0;
        if(dp[index]!=-1)return dp[index];
        int ans = 1e9;
        for(int i=index;i<s.size();i++){
           if(check(s,index,i)){
               ans = min(ans,1+sub(s,i+1,n));
           }
        }
        return dp[index]=ans;
    }
public:
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        return sub(s,0,n);
    }
};