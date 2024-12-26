class Solution {
private:
    map<pair<int,int>,int>dp;
    int solve(vector<int>&nums , int target , int index){
        if(index == nums.size())return target == 0;
        if(dp.count({target , index}))return dp[{target , index}];
        int ans = 0;
        ans += solve(nums , target - nums[index] , index + 1);
        ans += solve(nums , target + nums[index] , index + 1);
        return dp[{target , index}] = ans;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums , target , 0);
    }
};