class Solution {
private:
    int sub(vector<vector<int>>&dp,vector<int>&ranges,int index,int n,int len,int last){
        if(len>=n){
            return 0;
        }
        if(index==ranges.size())return 1e9;
        if(dp[index][len]!=-1)return dp[index][len];
        int notpick = sub(dp,ranges,index+1,n,len,last);
        int pick=1e9;
        if(len>=(index-ranges[index])){
         int x = max(len,index+ranges[index]);
         pick = 1+sub(dp,ranges,index+1,n,x,index);
        }
        return dp[index][len]=min(pick,notpick);
    }
public:
    int minTaps(int n, vector<int>& ranges) {
        // vector<vector<int>>dp(n+1,vector<int>(n,-1));
        // int res = sub(dp,ranges,0,n,0,-1);
        // return res>=1e9?-1:res;
        vector<int> dp(n + 1, n + 2); 
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            int tapRange = ranges[i];
            int left = max(0, i - tapRange);
            int right = min( i + tapRange,n);

            for (int j = left; j <= right; j++) {
                dp[j] = min(dp[j], dp[left] + 1);
            }
        }

        return dp[n] <= n + 1 ? dp[n] : -1;
      
    }
};