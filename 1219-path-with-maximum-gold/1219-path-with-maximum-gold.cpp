class Solution {
private:
    int n,m;
    bool check(int row,int col){
        return row>=0&&col<m&&row<n&&col>=0;
    }
    int sub(vector<vector<int>>&grid,int row,int col){
        int ans = grid[row][col];
        if(check(row+1,col)&&grid[row+1][col]!=0){
            int val = grid[row][col];
            grid[row][col]=0;
            ans = max(ans,val+sub(grid,row+1,col));
            grid[row][col]=val;
        }
        if(check(row-1,col)&&grid[row-1][col]!=0){
            int val = grid[row][col];
            grid[row][col]=0;
            ans = max(ans,val+sub(grid,row-1,col));
            grid[row][col]=val;
        }
        if(check(row,col+1)&&grid[row][col+1]!=0){
            int val = grid[row][col];
            grid[row][col]=0;
            ans = max(ans,val+sub(grid,row,col+1));
            grid[row][col]=val;
        }
        if(check(row,col-1)&&grid[row][col-1]!=0){
            int val = grid[row][col];
            grid[row][col]=0;
            ans = max(ans,val+sub(grid,row,col-1));
            grid[row][col]=val;
        }
        return ans;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int answer = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0)answer = max(answer,sub(grid,i,j));
            }
        }
        return answer;
    }
};