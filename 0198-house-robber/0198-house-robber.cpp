class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n,0);
        dp[0]=nums[0];
        dp[1]=nums[1];
        for(int i=2;i<n;i++){
            int maxprofit=INT_MIN;
            for(int j=i-2;j>=0;j--){
                if(nums[i]+dp[j]>maxprofit){
                    maxprofit=nums[i]+dp[j];
                }
            }
            dp[i]=maxprofit;
        }
        return *max_element(dp.begin(),dp.end());
    }
};