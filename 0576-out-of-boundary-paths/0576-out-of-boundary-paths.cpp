class Solution {
private:
    int dp[52][52][52];
    int mod = 1e9+7;
    bool check(int row,int col,int m,int n){
     return (row>=0&&col>=0&&row<m&&col<n);
    }
    int dfs(int m, int n, int move, int row, int col){
        if(!check(row,col,m,n))return 1;
        if( dp[row+1][col+1][move+1]!=-1)return  dp[row+1][col+1][move+1];
        int ans = 0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
           if(move!=0){
            ans = (ans + dfs(m,n,move-1,row+dx[i],col+dy[i]))%mod;
           }
        }
        return dp[row+1][col+1][move+1]=ans%mod;
    }
   
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return dfs(m,n,maxMove,startRow,startColumn);
    }
};