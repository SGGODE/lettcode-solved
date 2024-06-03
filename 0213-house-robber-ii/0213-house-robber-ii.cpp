class Solution {
private:
    int dp[101][101];
    int sub(vector<int>&nums,int index,int n){
        if(index>(n-1))return 0;
        if(dp[index][n]!=-1)return dp[index][n];
        int ans = 0;
        ans = max(ans,nums[index]+sub(nums,index+2,n));
        ans = max(ans,sub(nums,index+1,n));
        return dp[index][n]=ans;
    }
public:
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        if(n==1)return nums[0];
        return max(sub(nums,0,n-1),sub(nums,1,n));
    }
};