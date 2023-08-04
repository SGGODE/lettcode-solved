class Solution {
private:
    bool sub(vector<vector<int>>&dp,set<string>&sets,string&s,int start,int end){
        if(sets.find(s.substr(start,(end-start)+1))!=sets.end()){
            return 1;
        }
        if(start==end)return 0;
        if(dp[start][end]!=-1)return dp[start][end];
        bool ans = 0;
        for(int i=start;i<end;i++){
            ans = max(ans,sub(dp,sets,s,start,i)&&sub(dp,sets,s,i+1,end));
        }
        return dp[start][end]=ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       int n = s.size();
       set<string>sets(wordDict.begin(),wordDict.end());
       vector<vector<int>>dp(n,vector<int>(n,-1));
       return sub(dp,sets,s,0,n-1);
    }
};