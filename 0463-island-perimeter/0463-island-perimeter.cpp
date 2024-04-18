class Solution {
private:
    int n,m;
    bool check(int row,int col){
        return row<n&&col<m&&row>=0&&col>=0;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int peri = 0;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(grid[i][j]==1){
                  int cnt = 4;
                  if(check(i,j-1)&&grid[i][j-1]==1)cnt-=1;
                  if(check(i,j+1)&&grid[i][j+1]==1)cnt-=1;
                  if(check(i+1,j)&&grid[i+1][j]==1)cnt-=1;
                  if(check(i-1,j)&&grid[i-1][j]==1)cnt-=1;
                  peri+=cnt;
              }
           }
        }
        return peri;
    }
};