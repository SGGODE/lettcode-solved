class Solution {
private:
    bool sub(vector<int>&dp,vector<int>&nums,int index){
        if(index+3==nums.size()){
            bool flag=1,flag1=1;
            for(int i=index+1;i<nums.size();i++){
                if(nums[i]!=nums[i-1]){
                    flag=0;break;
                }
            }
            for(int i=index+1;i<nums.size();i++){
                if(nums[i]-nums[i-1]!=1){
                    flag1=0;break;
                }
            }
            return (flag||flag1);
        }
       if(index+2==nums.size()){
           return nums[index]==nums[index+1];
       }
       if(index+1==nums.size())return 0;
       if(dp[index]!=-1)return dp[index];
       bool ans = 0;
       if(nums[index]==nums[index+1]){
           ans=max(ans,sub(dp,nums,index+2));
       }
       if(nums[index]==nums[index+1]&&nums[index]==nums[index+2]){
           ans=max(ans,sub(dp,nums,index+3));
       }
       if(nums[index+1]-nums[index]==1&&nums[index+2]-nums[index+1]==1){
           ans=max(ans,sub(dp,nums,index+3));
       }
        return dp[index]=ans;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1); 
        return sub(dp,nums,0);
    }
};