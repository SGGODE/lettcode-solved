class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>>res(n,vector<int>(n,0));
      int total=n*n;
      int count=1;
      int rowstart=0,rowend=n-1;
      int colstart=0,colend=n-1;
      while(count<=total){
          for(int i=colstart;i<=colend&&count<=total;i++){
              res[rowstart][i]=count;
              ++count;
          }
          ++rowstart;
          for(int i=rowstart;i<=rowend&&count<=total;i++){
              res[i][colend]=count;
              ++count;
          }
          --colend;
          for(int i=colend;i>=colstart&&count<=total;i--){
              res[rowend][i]=count;
              ++count;
          }
          --rowend;
          for(int i=rowend;i>=rowstart&&count<=total;i--){
              res[i][colstart]=count;
              ++count;
          }
          ++colstart;
      }
        return res;
    }
};