class Solution {
private:
    int sub(vector<vector<int>>&dp,vector<int>&nums,int index,int last){
        if(index==nums.size()-1)return 0;
        if(dp[index][last]!=-1)return dp[index][last];
        int ans=1e9;
        if(nums[index+1]!=last){
            ans=min(ans,sub(dp,nums,index+1,last));
        }else{
            if(last==1&&nums[index]!=2){
                ans=min(ans,1+sub(dp,nums,index+1,2));
            }
            if(last==1&&nums[index]!=3){
                ans=min(ans,1+sub(dp,nums,index+1,3));
            }
            if(last==2&&nums[index]!=1){
                ans=min(ans,1+sub(dp,nums,index+1,1));
            }
            if(last==2&&nums[index]!=3){
                ans=min(ans,1+sub(dp,nums,index+1,3));
            }
            if(last==3&&nums[index]!=1){
                ans=min(ans,1+sub(dp,nums,index+1,1));
            }
            if(last==3&&nums[index]!=2){
                ans=min(ans,1+sub(dp,nums,index+1,2));
            }
        }
        return dp[index][last]=ans;
    }
public:
    int minSideJumps(vector<int>&nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return sub(dp,nums,0,2);
    }
};