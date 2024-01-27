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
        int dp[1001][1001] = {1};  
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x <= min(j, i - 1); x++) {
                    
                    if (j - x >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % 1000000007;
                    }
                }
            }
        }

        return dp[n][k];
    }
};