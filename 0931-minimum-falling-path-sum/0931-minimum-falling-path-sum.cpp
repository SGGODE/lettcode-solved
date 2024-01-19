class Solution {
private:
    bool check(int row,int col,int&n,int&m){
        return row>=0&&col>=0&&row<n&&col<m;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(i-1,j-1,n,m))dp[i][j]=min(dp[i][j],matrix[i][j]+dp[i-1][j-1]);
                if(check(i-1,j+1,n,m))dp[i][j]=min(dp[i][j],matrix[i][j]+dp[i-1][j+1]);
                if(check(i-1,j,n,m))dp[i][j]=min(dp[i][j],matrix[i][j]+dp[i-1][j]);
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};