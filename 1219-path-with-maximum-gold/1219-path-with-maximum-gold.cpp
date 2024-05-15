class Solution {
private:
    int n,m;
    bool check(int row,int col){
        return row>=0&&col<m&&row<n&&col>=0;
    }
    int sub(vector<vector<int>>&grid,int row,int col){
        int ans = grid[row][col];
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int val = grid[row][col];
            grid[row][col]=0;
            if(check(row+dx[i],col+dy[i])&&grid[row+dx[i]][col+dy[i]]!=0){
                ans = max(ans,val+sub(grid,row+dx[i],col+dy[i]));
            }
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