class Solution {
private:
    int dp[1001];
    int sub(string&s,int index){
        if(index==s.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int ans = 1e9;
        unordered_map<int,int>count;
        int mp[26]={0};
        for(int i=index;i<s.size();i++){
            if(mp[s[i]-'a']!=0){
                if(count[mp[s[i]-'a']]==1){
                    count.erase(mp[s[i]-'a']);
                }else --count[mp[s[i]-'a']];
                mp[s[i]-'a']++;
                count[mp[s[i]-'a']]++;
                if(count.size()==1){
                    ans = min(ans,1+sub(s,i+1));
                }
            }else{
                mp[s[i]-'a']++;
                count[mp[s[i]-'a']]++;
                if(count.size()==1){
                    ans = min(ans,1+sub(s,i+1));
                }
            }
        }
        return dp[index]=ans;
    }
public:
    int minimumSubstringsInPartition(string&s) {
        memset(dp,-1,sizeof(dp));
        return sub(s,0);
    }
};