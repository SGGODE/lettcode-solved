class Solution {
private:
    static bool cmp(const std::vector<int>& a, const std::vector<int>& b) {
    return a[1] < b[1];
  }

    int sub(vector<vector<int>>&dp,vector<vector<int>>&nums,int index,int end,int last){
        if(index==nums.size())return 0;
        if(dp[index][last+1]!=-1)return dp[index][last+1];
        int notpick = sub(dp,nums,index+1,end,last);
        int pick = 0;
        if(end==INT_MIN||end<=nums[index][0]){
            pick = 1 + sub(dp,nums,index+1,nums[index][1],index);
        }
        return dp[index][last+1]=max(pick,notpick);
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>&nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),cmp);
        // int x = INT_MIN;
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return n-sub(dp,nums,0,x,-1);
        int len = 0;
        int last = nums[0][1];
        for(int i=1;i<n;i++){
            if(nums[i][0]>=last){
                last = nums[i][1];
            }else{
                len+=1;
                last=min(last,nums[i][1]);
            }
        }
        return len;
    }
};