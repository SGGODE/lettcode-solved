class Solution {
private:
    int dp[101];
    int sub(string&s,map<int,char>&mp,int index){
        if(index==s.size())return 1;
        if(s[index]=='0')return 0;
        if(dp[index]!=-1)return dp[index];
        int ans = 0;
        string x;
        for(int i=index;i<s.size();i++){
            x.push_back(s[i]);
            if(stoi(x)<=26){
                ans += sub(s,mp,i+1);
            }else break;
        }
        return dp[index]=ans;
    }
public:
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        map<int,char>mp;
        char ch = 'A';
        mp[1]=ch;
        for(int i=1;i<26;i++){
            mp[i+1]=ch+i;
        }
        return sub(s,mp,0);
    }
};