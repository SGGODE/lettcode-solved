class Solution {
private:
    int dp[2001][4000];
    int sub(vector<int>&nums,int index,int sum){
        if(index==nums.size())return 0;
        if(dp[index][sum]!=-1)return dp[index][sum];
        int ans = 0;
        if(sum<nums[index]){
            ans = max(ans,nums[index]+sub(nums,index+1,sum+nums[index]));
        }
        ans = max(ans,sub(nums,index+1,sum));
        return dp[index][sum]=ans;
    }
public:
    int maxTotalReward(vector<int>&nums) {
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return sub(nums,0,0);
    }
};