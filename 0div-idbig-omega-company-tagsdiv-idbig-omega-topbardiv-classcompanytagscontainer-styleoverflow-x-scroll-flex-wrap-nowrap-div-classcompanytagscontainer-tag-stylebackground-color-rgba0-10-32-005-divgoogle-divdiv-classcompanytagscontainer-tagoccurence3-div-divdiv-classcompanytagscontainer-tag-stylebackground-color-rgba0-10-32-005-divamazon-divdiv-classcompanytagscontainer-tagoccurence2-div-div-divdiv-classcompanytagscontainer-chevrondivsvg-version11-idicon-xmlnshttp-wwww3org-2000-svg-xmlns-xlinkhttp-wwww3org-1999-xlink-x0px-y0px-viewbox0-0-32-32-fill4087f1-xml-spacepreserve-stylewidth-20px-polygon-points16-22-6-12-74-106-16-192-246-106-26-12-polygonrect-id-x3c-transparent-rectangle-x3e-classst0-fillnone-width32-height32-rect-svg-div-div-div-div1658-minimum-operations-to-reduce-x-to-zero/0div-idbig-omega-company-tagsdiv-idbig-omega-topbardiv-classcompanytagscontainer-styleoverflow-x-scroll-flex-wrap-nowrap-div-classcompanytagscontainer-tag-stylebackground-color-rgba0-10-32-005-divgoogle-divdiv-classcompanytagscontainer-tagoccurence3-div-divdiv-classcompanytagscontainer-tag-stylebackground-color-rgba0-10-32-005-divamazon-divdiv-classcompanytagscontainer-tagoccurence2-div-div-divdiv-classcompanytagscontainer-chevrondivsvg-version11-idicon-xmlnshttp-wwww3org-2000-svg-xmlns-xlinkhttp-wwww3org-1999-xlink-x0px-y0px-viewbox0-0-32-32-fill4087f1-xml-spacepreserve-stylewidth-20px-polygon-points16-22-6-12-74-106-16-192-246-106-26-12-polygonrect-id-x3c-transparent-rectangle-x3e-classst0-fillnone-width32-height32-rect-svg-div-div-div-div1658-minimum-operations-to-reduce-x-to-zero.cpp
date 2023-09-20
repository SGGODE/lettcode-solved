class Solution {
private:
    int sub(vector<vector<int>>&dp,vector<int>&nums,int start,int end,int sum){
        if(sum==0)return 0;
        if(start==end&&nums[start]==sum)return 1;
        if(start>end)return 1e9;
        if(dp[start][sum]!=-1)return dp[start][sum];
        if(dp[end][sum]!=-1)return dp[end][sum];
        int ans = 1e9;
        if(sum>=nums[start]){
            ans = min(ans,1+sub(dp,nums,start+1,end,sum-nums[start]));
        }
        if(sum>=nums[end]){
            ans = min(ans,1+sub(dp,nums,start,end-1,sum-nums[end]));
        }
        return dp[start][sum]=dp[end][sum]=ans;
    }
public:
    int minOperations(vector<int>& nums, int x) {
      //  int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(x+1,-1));
        // int res = sub(dp,nums,0,n-1,x);
        // return res>=1e9?-1:res;
         int target = 0, n = nums.size();
        for (int num : nums) target += num;
        target -= x;
        
        if (target == 0) return n;
        
        int max_len = 0, cur_sum = 0, left = 0;
        
        for (int right = 0; right < n; ++right) {
            cur_sum += nums[right];
            while (left <= right && cur_sum > target) {
                cur_sum -= nums[left];
                left++;
            }
            if (cur_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        return max_len ? n - max_len : -1;
    }
};