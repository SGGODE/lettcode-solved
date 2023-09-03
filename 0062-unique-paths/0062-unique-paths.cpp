class Solution {
private:
    int sub(vector<vector<int>>&dp,int row,int col,int n,int m){
        if((row<0||col<0)||(row>=n||col>=m))return 0;
        if(row==n-1&&col==m-1){
            return 1;
        }
        if(dp[row][col]!=-1)return dp[row][col];
        int right = sub(dp,row,col+1,n,m);
        int down = sub(dp,row+1,col,n,m);
        return dp[row][col]=right+down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return sub(dp,0,0,m,n);
    }
};