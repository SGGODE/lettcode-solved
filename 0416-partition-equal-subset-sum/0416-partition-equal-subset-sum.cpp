class Solution {
private:
    bool combination(vector<int>&nums,vector<vector<int>>&dp,int sum,int index){
        if(sum==0)return 1;
        if(index==0)return sum==nums[0];
        if(dp[index][sum]!=-1)return dp[index][sum];
        bool notpick=combination(nums,dp,sum,index-1);
        bool pick=0;
        if(sum>=nums[index]){
            pick=combination(nums,dp,sum-nums[index],index-1);
        }
        return dp[index][sum]=(pick||notpick);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &it:nums)sum+=it;
        if(sum%2)return 0;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        return combination(nums,dp,sum/2,n-1);
    }
};