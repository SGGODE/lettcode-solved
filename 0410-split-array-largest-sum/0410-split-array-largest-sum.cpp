class Solution {
private:
    int sub(vector<vector<int>>&dp,vector<int>&nums,int index,int k){
        if(index==nums.size()&&k!=0)return -1e9;
        if(k==0){
            int sum=0;
            for(int i=index;i<nums.size();i++)sum+=nums[i];
            return sum;
        }
        if(dp[index][k]!=-1)return dp[index][k];
        int ans = INT_MAX;
        int sum=0;
        for(int i=index;i<nums.size();i++){
            sum+=nums[i];
            int ans1 = max(sum,sub(dp,nums,i+1,k-1));
            ans=min(ans,ans1);
        }
        return dp[index][k]=ans;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return sub(dp,nums,0,k-1);
    }
};