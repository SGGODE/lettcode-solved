class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = 0;
        int e = matrix[0].size()-1;
        while(s<matrix.size()){
            if(matrix[s][e]<target){
                s++;
               // continue;
            }else{
                for(int i = 0; i <= e; i++){
                    if(matrix[s][i]==target)return 1;
                }
                return 0;
            } 
        }
        return 0;
    }
};