class Solution {
private:
    int n,m;
    bool solve(vector<vector<char>>& grid){
      for(size_t i=0;i<n;i++){
          for(size_t j=0;j<m;j++){
              if(grid[i][j]=='.'){
                  for(char k='1';k<='9';k++){
                      if(valid(i,j,grid,k)){
                          grid[i][j]=k;
                      
                      if(solve(grid)==1)
                          return 1;
                      else 
                          grid[i][j]='.'; 
                      }
                  }
                  return 0;
              }
          }
      }
        return 1;
    }
    bool valid(int i,int j,vector<vector<char>>& grid,char c){
        for(int k=0;k<9;k++){
            if(grid[i][k]==c)return 0;
            if(grid[k][j]==c)return 0;
            if(grid[3*(i/3)+k/3][3*(j/3)+k%3]==c)return 0;
        }
        return 1;
    }
    
public:
    void solveSudoku(vector<vector<char>>& grid) {
         n=grid.size();
      m=grid[0].size();
        solve(grid);
    }
    
};