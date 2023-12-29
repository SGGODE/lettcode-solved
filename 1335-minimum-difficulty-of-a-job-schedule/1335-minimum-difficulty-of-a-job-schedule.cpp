class Solution {
private:
    int dp[301][11];
    int sub(vector<int>&nums,int index,int d){
        if(index==nums.size()&&d==0)return 0;
        if(d==0)return 1e9;
        if(index==nums.size())return 1e9;
        if(dp[index][d]!=-1)return dp[index][d];
        int ans = 1e9;
        int val = 0;
        for(int i=index;i<nums.size();i++){
            val = max(val,nums[i]);
            ans = min(ans,val+sub(nums,i+1,d-1));
        }
        return dp[index][d]=ans;
    }
public:
    int minDifficulty(vector<int>&nums, int d) {
      memset(dp,-1,sizeof(dp));
      int res = sub(nums,0,d);   
      return res>=1e9?-1:res;
    }
};