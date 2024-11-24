class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        int b = n/k;
        unordered_map<string,int>dp;
        for(int i = 0; i < n; i+=b){
            dp[s.substr(i,b)]++;
        }
        for(int i = 0; i < n; i+=b){
            dp[t.substr(i,b)]--;
        }
        for(auto&it:dp){
            if(it.second)return 0;
        }
        return 1;
    }
};