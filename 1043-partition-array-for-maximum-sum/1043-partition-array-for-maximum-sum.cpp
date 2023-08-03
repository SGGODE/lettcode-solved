class Solution {
private:
    int sub(vector<vector<int>>&dp,vector<int>&arr,int start,int end,int k){
        if(start==end)return 0;
        if(dp[start][end]!=-1)return dp[start][end];
        int ans = INT_MIN;
        int m = 0;
        for(int i = start;i<(start+k)&&i<end;i++){
            m = max(m,arr[i]);
            ans=max(ans,(m*((i-start)+1)+sub(dp,arr,i+1,end,k)));
        }
        return dp[start][end]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return sub(dp,arr,0,n,k);
    }
};