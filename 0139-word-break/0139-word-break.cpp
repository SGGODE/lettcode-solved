class Solution {
private:
    bool sub(vector<vector<int>>&dp,string&s,int start,int end,set<string>&sets){
       // cout<<s.substr(start,(end-start))<<" "<<start<<" "<<end<<endl;
        if(sets.find(s.substr(start,(end-start)+1))!=sets.end()){
          //  cout<<start<<" "<<end<<" "<<s.substr(start,(end-start))<<endl;
            return 1;
        }
        if(dp[start][end]!=-1)return dp[start][end];
        if(start>=end)return 0;
        bool ans = 0;
        for(int i=start;i<end;i++){
            ans=max(ans,(sub(dp,s,start,i,sets)&&sub(dp,s,i+1,end,sets)));
          //  if(ans)return 1;
        }
        return dp[start][end]=ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string>sets;
        for(const auto&it:wordDict)sets.insert(it);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return sub(dp,s,0,n-1,sets);
    }
};