class Solution {
private:
    bool check(int row,int col){
        return row<3&&col<3&&row>=0&&col>=0;
    }
    bool checkx(vector<vector<char>>& grid,int i,int j){
        int cnt = 0;
        if(check(i+1,j)&&grid[i][j]==grid[i+1][j]&&check(i,j+1)&&grid[i][j]==grid[i][j+1])return 1;
        if(check(i-1,j)&&grid[i][j]==grid[i-1][j]&&check(i,j+1)&&grid[i][j]==grid[i][j+1])return 1;
        if(check(i+1,j)&&grid[i][j]==grid[i+1][j]&&check(i,j-1)&&grid[i][j]==grid[i][j-1])return 1;
        if(check(i-1,j)&&grid[i][j]==grid[i-1][j]&&check(i,j-1)&&grid[i][j]==grid[i][j-1])return 1;
        return 0;
    }
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(checkx(grid,i,j)){
                    return 1;
                }
            }
        }
        return 0;
    }
};