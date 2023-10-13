class Solution {
private:
    int dp[1001];
    int sub(vector<int>&nums,int index){
        if(index>=nums.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int ans = 1e9;
        if(index==0){
             ans = min(ans,min(nums[index]+sub(nums,index+1),min(nums[index]+sub(nums,index+2),sub(nums,index+1))));
        }else{
            ans = min(ans,min(nums[index]+sub(nums,index+1),nums[index]+sub(nums,index+2)));
        }
        return dp[index]=ans;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return sub(cost,0);
    }
};