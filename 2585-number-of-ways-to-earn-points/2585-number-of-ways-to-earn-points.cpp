class Solution {
private:
    int mod=1e9+7;
    int sub(vector<vector<int>>&dp,vector<vector<int>>&nums,int sum,int index){
        if(sum==0)return 1;
        if(index==nums.size())return 0;
        if(dp[index][sum]!=-1)return dp[index][sum];
        long long int notpick=sub(dp,nums,sum,index+1);
        long long int pick=0;
        int xsum=0;
        for(int i=0;i<nums[index][0];i++){
            xsum+=nums[index][1];
            if(xsum<=sum){
               pick+=sub(dp,nums,sum-xsum,index+1); 
            }
        }
        return dp[index][sum]=(pick+notpick)%mod;
    }
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return sub(dp,types,target,0);
    }
};