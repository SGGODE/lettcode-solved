class Solution {
private:
    int sub( vector<vector<vector<int>>>&dp,vector<string>&nums,int index,int m,int n){
        if(index==nums.size())return 0;
        if(dp[index][m][n]!=-1)return dp[index][m][n];
        int notpick = sub(dp,nums,index+1,m,n);
        int pick = 0;
        int one=0,zero=0;
        for(int i=0;i<nums[index].size();i++){
            if(nums[index][i]=='0')++zero;
            else ++one;
        }
        if(one<=n&&zero<=m){
            pick=1+sub(dp,nums,index+1,m-zero,n-one);
        }
        return dp[index][m][n]=max(pick,notpick);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>>dp(len,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return sub(dp,strs,0,m,n);
    }
};