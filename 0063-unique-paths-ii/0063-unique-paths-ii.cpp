class Solution {
private:
    int mod=2*1e9;
    int sub(vector<vector<int>>&nums,vector<vector<int>>&dp,int row,int col){
        if(row>=nums.size()||col>=nums[0].size())return 0;
        if(nums[row][col]==1)return 0;
        if(row==nums.size()-1&&col==nums[0].size()-1)return 1;
        if(dp[row][col]!=-1)return dp[row][col];
        int left = sub(nums,dp,row,col+1);
        int down = sub(nums,dp,row+1,col);
        return dp[row][col]=(left+down)%mod;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>&nums) {
        int n = nums.size();
        int m = nums[0].size();
        if(nums[0][0]==1||nums[n-1][m-1]==1)return 0;
        if(n==1&&m==1&&nums[0][0]==0)return 1;
        if(n==1&&m==1&&nums[0][0]==1)return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        sub(nums,dp,0,0);
        return dp[0][0]==-1?0:dp[0][0];
       // return dp[0][0];
    }
};