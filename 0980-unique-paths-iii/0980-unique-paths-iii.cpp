class Solution {
private:
    int n,m,start_row=0,start_col=0,end_col=0,end_row=0,space=0,result=0;
    bool check(int i,int j){
      return i>=0&&j<m&&i<n&&j>=0;
      return 0;
    }
     int dx[4]={0,-1,0,1};
     int dy[4]={1,0,-1,0};
    void path(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j,int run){
        if(i==end_row&&j==end_col){
            if(run==space+1)result+=1;
            return;
        }
       
       // if(i>=0&&i<n&&j>=0&&j<m&&!vis[i][j]&&grid[i][j]!=-1){
         grid[i][j]=-1;
         for(int k=0;k<4;k++){
             if(check(i+dx[k],j+dy[k])&&grid[i+dx[k]][j+dy[k]]!=-1)
                path(grid,vis,i+dx[k],j+dy[k],run+1);
         }
             grid[i][j]=0;
       // }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    start_row=i;
                    start_col=j;
                    //end=j;
                }
                if(grid[i][j]==2){
                    end_row=i;
                    end_col=j;
                }
                if(grid[i][j]==0)space+=1;
            }
        }
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        path(grid,vis,start_row,start_col,0);
        return result;
    }
};