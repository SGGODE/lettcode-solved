class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<1;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=matrix[i][j];
            }
            for(int j=0;j<n;j++){
                dp[j][i]=matrix[j][i];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+matrix[i][j];
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=dp[i][j];
            }
        }
        return sum;
    }
};