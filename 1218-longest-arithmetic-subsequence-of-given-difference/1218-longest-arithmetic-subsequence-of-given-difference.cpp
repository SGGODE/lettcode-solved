class Solution {
public:
    int longestSubsequence(vector<int>&nums, int sum) {
        int n = nums.size();
        vector<int>dp(n,1);
        map<int,int>mp;
        //for(auto&it:nums)mp[it]++;
        for(int i=0;i<n;i++){
            bool flag=0;
            // if(mp.count(nums[i]+sum)){
            //     dp[i]=max(dp[i],mp[nums[i]+sum]+1);
            //    // continue;
            //     mp[nums[i]]=dp[i];
            //     flag=1;
            // }
            if(mp.count(nums[i]-sum)){
                dp[i]=max(dp[i],mp[nums[i]-sum]+1);
                //continue;
                mp[nums[i]]=dp[i];
                flag=1;
            }
            if(!flag)mp[nums[i]]=1;
        }
        return *max_element(dp.begin(),dp.end());
    }
};