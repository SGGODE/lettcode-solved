class Solution {
private:
    int sub(vector<int>&dp,set<string>&nums,string&s,int index){
        if(index==s.size())return 0;
        int ans = 1e9;
        string x;
        if(dp[index]!=-1)return dp[index];
        for(int i=index;i<s.size();i++){
            x.push_back(s[i]);
            if(nums.count(x)){
               ans=min(ans,sub(dp,nums,s,i+1)); 
            }else{
                ans=min(ans,((i-index)+1)+sub(dp,nums,s,i+1));
            }
        }
        return dp[index]=ans;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int>dp(n,-1);
        set<string>nums(dictionary.begin(),dictionary.end());
        return sub(dp,nums,s,0);
    }
};