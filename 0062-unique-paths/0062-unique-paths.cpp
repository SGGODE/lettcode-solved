class Solution {
private:
    int sub(vector<vector<int>>&dp,int row,int col,int m,int n){
        if((row<0||col<0)||(row>=m||col>=n))return 0;
        if(row==m-1&&col==n-1)return 1;
        if(dp[row][col]!=-1)return dp[row][col];
        int down = sub(dp,row+1,col,m,n);
        int left = sub(dp,row,col+1,m,n);
        return dp[row][col]=left+down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return sub(dp,0,0,m,n);
    }
};