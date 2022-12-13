class Solution {
private:
    int minpath=INT_MAX,n,m;
    bool check(int i,int j){
          if(i<0||j<0||i>=n||j>=m)return 0;
        return 1;
    }
    void call(vector<vector<int>>&matrix,int i,int j,int sum){
        int minval=INT_MAX;
       if(check(i-1,j+1))
         minval=min(minval,(matrix[i][j]+matrix[i-1][j+1]));
       if(check(i-1,j))
          minval=min(minval,(matrix[i-1][j]+matrix[i][j]));
       if(check(i-1,j-1))
           minval=min(minval,(matrix[i][j]+matrix[i-1][j-1]));
        matrix[i][j]=minval;
        //matrix[i][j]=min((matrix[i][j]+matrix[i-1][j+1]),min((matrix[i-1][j]+matrix[i][j]),(matrix[i][j]+matrix[i-1][j-1])));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
         n=matrix.size();
         m=matrix[0].size();
        for(int i=1;i<n;i++){
          for(int j=0;j<m;j++){
              call(matrix,i,j,matrix[i][j]);
          }  
        }
        for(int i=n-1;i<n;i++){
            for(int j=0;j<m;j++){
                minpath=min(minpath,matrix[i][j]);
            }
        }
        return minpath;
    }
};