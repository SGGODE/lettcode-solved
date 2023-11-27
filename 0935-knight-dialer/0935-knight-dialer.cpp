class Solution {
private:
    int m = 1e9+7;
    int dp[5001][10];
    int dfs(map<int,vector<int>>&mp,int src,int n){
        if(n==0)return 1;
        if(dp[n][src]!=-1)return dp[n][src];
        int sum = 0;
        for(auto&it:mp[src]){
            sum = (sum + dfs(mp,it,n-1))%m;
        }
        return dp[n][src]=sum%m;
    }
public:
    int knightDialer(int n) {
        map<int,vector<int>>mp;
        mp[1].push_back(6);mp[1].push_back(8);mp[0].push_back(6);
        mp[0].push_back(4);mp[2].push_back(9);mp[2].push_back(7);
        mp[3].push_back(8);mp[3].push_back(4);mp[4].push_back(9);
        mp[4].push_back(3);mp[4].push_back(0);mp[6].push_back(0);
        mp[6].push_back(1);mp[6].push_back(7);mp[7].push_back(6);
        mp[7].push_back(2);mp[8].push_back(1);mp[8].push_back(3);
        mp[9].push_back(2);mp[9].push_back(4);
        int sum = 0;
        memset(dp,-1,sizeof(dp));
        int mod = 1e9+7;
        for(int i=0;i<=9;i++){
            sum = (sum + dfs(mp,i,n-1))%mod;
        }
        return sum%mod;
    }
};