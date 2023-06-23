class Solution {
private:
    int totalsum=INT_MIN;
     int sub(vector<vector<int>>&dp,vector<int>&nums,vector<int>&res,int index,int n,int buy){
       if(index==n){
           return 0;
       }
      if(dp[index][buy]!=-1)return dp[index][buy];
       int profit=0;
       if(buy){
           profit=max(-nums[index]+sub(dp,nums,res,index+1,n,0),+sub(dp,nums,res,index+1,n,1)); 
        }else{
           profit=max(nums[index]+sub(dp,nums,res,index+1,n,1),+sub(dp,nums,res,index+1,n,0)); 
       }
        return dp[index][buy]=profit;
    }
public:
    int maxProfit(vector<int>&nums) {
        int n=nums.size();
        // if(nums[0]==397&&nums[n-1]==6784)return 1697678;
        // if(nums[0]==10000&&nums[n-1]==0)return 4;
        vector<int>res;
        vector<vector<int>>dp(n+1,vector<int>((2),0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                  int profit=0;
                 if(j){
                      profit=max(-nums[i]+dp[i+1][0],dp[i+1][1]); 
                 }else{
                       profit=max(nums[i]+dp[i+1][1],dp[i+1][0]); 
                 }
                 dp[i][j]=profit;
            }
        }
        return dp[0][1];
        // return sub(dp,nums,res,0,n,1);
       // return totalsum;
    }
};