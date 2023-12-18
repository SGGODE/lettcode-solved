class Solution {
private:
    int dp[301][1001];
    bool sub(string&s,vector<string>&word,int index,int dictindex){
        if(index==s.size())return 1;
        if(dictindex==word.size())return 0;
        if(dp[index][dictindex]!=-1)return dp[index][dictindex];
        bool ans = 0;
        ans = max(ans,sub(s,word,index,dictindex+1));
        if(s[index]==word[dictindex][0]){
            int j = 0;int id=index;
            while(id<s.size()&&j<word[dictindex].size()&&s[id]==word[dictindex][j]){
                ++j;++id;
            }
            if(id<=s.size()&&j==word[dictindex].size()){
                ans = max(ans,sub(s,word,id,0));
            }
        }
        return dp[index][dictindex]=ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        return sub(s,wordDict,0,0);
       // int n = s.size();
        
    }
};