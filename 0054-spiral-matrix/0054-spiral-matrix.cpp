class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>v;
        int n=matrix.size();
        int count=0;
        int m=matrix[0].size();
          int total=n*m;
        int rowstart=0,rowend=n-1;
        int colstart=0,colend=m-1;
        while(rowstart<=rowend&&colstart<=colend){
       // int j=0;
        for(int i=colstart;i<=colend&&count<total;i++){
            v.push_back(matrix[rowstart][i]);
            ++count;
        }++rowstart;
        for(int k=rowstart;k<=rowend&&count<total;k++){
            v.push_back(matrix[k][colend]);
            ++count;
        }--colend;
        for(int l=colend;l>=colstart&&count<total;l--){
            v.push_back(matrix[rowend][l]);
            ++count;
        }--rowend; 
        for(int h=rowend;h>=rowstart&&count<total;h--){
            v.push_back(matrix[h][colstart]);
            ++count;
        }
        ++colstart;
    }
        return v;
    }
};