class Solution {
private:
    int sub(vector<vector<int>>&dp,vector<int>&nums,int start,int end){
        if(start>end)return 0;
        if(dp[start][end]!=-1)return dp[start][end];
        int ans=0;
        for(int i=start;i<=end;i++){
            ans=max(ans,(nums[start-1]*nums[i]*nums[end+1])+sub(dp,nums,start,i-1)+sub(dp,nums,i+1,end));
        }
        return dp[start][end]=ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        int n = nums.size(); 
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
      //  it=nums.begin()+2;
      //  nums.erase(it);
      //  for(auto&it:nums)cout<<it<<" ";
        //cout<<nums[1]<<" "<<nums[n-1]<<endl;
        return sub(dp,nums,1,n-2);
    }
};