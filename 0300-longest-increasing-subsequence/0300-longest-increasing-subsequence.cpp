class Solution {
private:
    int sub(vector<vector<int>>&dp,vector<int>&nums,int index,int last){
        if(index==nums.size()){
           // if(last>nums[0])return 1;
            return 0;
        }
       if(dp[index][last+1]!=-1)return dp[index][last+1];
        int notpick=sub(dp,nums,index+1,last);
        int pick=0;
        if(last==-1){
            pick=1+sub(dp,nums,index+1,index);
        }else{
            if(nums[index]>nums[last])pick=1+sub(dp,nums,index+1,index);
        }
        return dp[index][last+1]=max(pick,notpick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        //nums.push_back(1e5);
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return sub(dp,nums,0,-1);
       // return dp[n-1];
    }
};