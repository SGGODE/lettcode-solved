class Solution {
public:
    int rob(vector<int>& nums) {
        int maxmoney=0;
        int n=nums.size();
        vector<int>dp(n,-2);
        if(n==1||n==2)return *max_element(nums.begin(),nums.end()); 
        dp[0]=nums[0];dp[1]=nums[1];
        for(int i=2;i<n;i++){
            int money=0;
            dp[i]=nums[i];
            for(int j=i-2;j>=0;j--){
                money=max(money,dp[j]);
            }
            dp[i]+=money;
        }
        int m=*max_element(dp.begin(),dp.end());
        return m;
    }
};