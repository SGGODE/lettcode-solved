class Solution {
private:
    int solve(vector<int>&nums , int target , int index){
        if(index == nums.size())return target == 0;
        int ans = 0;
        ans += solve(nums , target - nums[index] , index + 1);
        ans += solve(nums , target + nums[index] , index + 1);
        return ans;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums , target , 0);
    }
};