class Solution {
private:
    int dp[201][201];
    int sub(vector<vector<int>>& grid,int last,int row){
        if(row==grid.size())return 0;
        if(dp[row][last+1]!=-1)return dp[row][last+1];
        int ans = 1e9;
        for(int i=0;i<grid[0].size();i++){
            if(last==-1){
                ans = min(ans,grid[row][i]+sub(grid,i,row+1));
            }else if(last!=-1&&last!=i){
                 ans = min(ans,grid[row][i]+sub(grid,i,row+1));
            }
        }
        return dp[row][last+1]=ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return sub(grid,-1,0);
    }
};