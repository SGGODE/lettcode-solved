class Solution {
private:
    int dp[501];
    int sub(vector<int>& arr,int index,int k){
        if(index==arr.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int ans = 0;
        int msum = 0;
        for(int i=index;i<index+k&&i<arr.size();i++){
            msum=max(msum,arr[i]);
            ans = max(ans,(msum*((i-index)+1))+sub(arr,i+1,k));
        }
        return dp[index]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return sub(arr,0,k);
    }
};