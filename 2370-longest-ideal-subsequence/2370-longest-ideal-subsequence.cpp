class Solution {
private:
    int dp[100001][27];
    int sub(string&s,map<char,int>&mp,int index,int lastval,int k){
        if(index==s.size())return 0;
        if(dp[index][lastval]!=-1)return dp[index][lastval];
        int ans = 0;
        ans = sub(s,mp,index+1,lastval,k);
        if(abs(mp[s[index]]-lastval)<=k||lastval==0){
            ans = max(ans,1+sub(s,mp,index+1,mp[s[index]],k));
        }
        return dp[index][lastval]=ans;
    }
public:
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof(dp));
        char ch = 'a';
        map<char,int>mp;
        mp[ch]=1;
        for(int i=1;i<26;i++){
            mp[ch+i]=i+1;
        }
        return sub(s,mp,0,0,k);
    }
};