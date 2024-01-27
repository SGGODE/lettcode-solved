class Solution {
private:
    int sub(int index,int n,int k){
        if(k==0)return 0;
        if(index>n)return 0;
        int ans = 0;
        ans = ans + sub(index+1,n,k);
        ans = ans + (1 + sub(index+1,n,k-1));
        return ans;
    }
public:
  int kInversePairs(int n, int k) {
         int mod = 1000000007;
        if (k > n*(n-1)/2 || k < 0) return 0;
        vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
            if (i + 1 <= n) dp[i + 1][0] = 1;
            for (int j = 1; j <= min(k, i*(i-1)/2); j++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if (j >= i) dp[i][j] -= dp[i-1][j-i];
                dp[i][j] = (dp[i][j]+mod) % mod;
            }
        }
        return (int) dp[n][k];
  }
};