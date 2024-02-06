class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>dp;
        for(auto&it:strs){
            string s = it;
            sort(s.begin(),s.end());
            dp[s].push_back(it);
        }
        vector<vector<string>>result;
        for(auto&it:dp){
            vector<string> temp = it.second;
            result.push_back(temp);
        }
        return result;
    }
};