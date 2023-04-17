class Solution {
public:
    int rob(vector<int>& nums) {
       int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
       vector<int>dp1(n,-1);
       vector<int>dp2(n,-1);
        dp1[0]=nums[0];
        dp1[1]=nums[1];
        for(int i=2;i<n-1;i++){
            int ans=INT_MIN;
            for(int j=i-2;j>=0;j--){
                ans=max(ans,nums[i]+dp1[j]);
            }
            dp1[i]=ans;
        }
        dp2[1]=nums[1];
        dp2[2]=nums[2];
        for(int i=3;i<n;i++){
            int ans=INT_MIN;
            for(int j=i-2;j>=0;j--){
                ans=max(ans,nums[i]+dp2[j]);
            }
            dp2[i]=ans;
        }
        return max(*max_element(dp1.begin(),dp1.end()),*max_element(dp2.begin(),dp2.end()));
    }
};