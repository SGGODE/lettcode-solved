class Solution {
private:
    int fun(vector<int>&nums,int sum,vector<int>&dp){
     //   if(sum==0)return 1;
        if(sum<0)return 0;
        if(sum==0)return 1;
        if(dp[sum]!=-1)return dp[sum];
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=fun(nums,sum-nums[i],dp);
        }
        return dp[sum]=cnt;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
       int n=nums.size();
       vector<int>dp(target+1,-1);
       return fun(nums,target,dp); 
    }
};