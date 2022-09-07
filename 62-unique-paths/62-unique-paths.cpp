class Solution {
private:
int get(vector<vector<int>>&dp,int n,int m){
    if(n==0 && m==0){
        return 1;
    }
    if(n<0 || m<0)
        return 0;
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    int left=get(dp,n-1,m);
    int right=get(dp,n,m-1);
    return dp[n][m]=left+right;
}
public:
    int uniquePaths(int m, int n) {
        /*int N=m+n-2;
        double s=1;
        int r=m-1;
        for(int i=1;i<=r;i++){
            s=s*(N-r+i)/i;
        }
        return (int)s;*/
        int dp[m][n];
        //vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 &&j==0)dp[i][j]=1;
                else{
                int left=0,right=0;
                if(i>0)
                  left=dp[i-1][j];
                if(j>0)
                  right=dp[i][j-1];
                dp[i][j]=left+right;
             }
            }
        }
        //return get(dp,m-1,n-1);
        return dp[m-1][n-1];
    }
};