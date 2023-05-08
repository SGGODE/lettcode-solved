class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        if(n%2){
            int sum=0;
            int j=0;
            for(int i=0;i<n&&j<n;i++){
                sum+=mat[i][j];
                ++j;
            }
            j=n-1;
            for(int i=0;i<n&&j>=0;i++){
                if(i==j){
                    --j;
                    continue;
                }
                else sum+=mat[i][j];
                --j;
            }
            return sum;
        }
        //int sum=0;
         int sum=0;
            int j=0;
            for(int i=0;i<n&&j<n;i++){
                sum+=mat[i][j];
                ++j;
            }
            j=n-1;
            for(int i=0;i<n&&j>=0;i++){
                // if(i==j){
                //     --j;
                //     continue;
                // }
                // else 
                sum+=mat[i][j];
                --j;
            }
            return sum;
        //return -1;
    }
};