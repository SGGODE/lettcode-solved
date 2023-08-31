class Solution {
private:
    int sub(vector<vector<int>>&dp,vector<int>&nums,int index,int d){
        if(d==0&&index!=nums.size())return 1e9;
        if(index==nums.size()&&d==0)return 0;
        if(index==nums.size()&&d!=0)return 1e9;
       if(dp[index][d]!=-1)return dp[index][d];
        int ans = 1e9;
        int var = INT_MIN;
        for(int i=index;i<nums.size();i++){
            var=max(var,nums[i]);
            ans=min(ans,var+sub(dp,nums,i+1,d-1));
        }
        return dp[index][d]=ans;
    }
public:
    int minDifficulty(vector<int>&nums, int d) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        int res= sub(dp,nums,0,d);
        return res>=1e9?-1:res;
    }
};