class Solution {
private:
    bool check(vector<vector<int>>&mat,int row,int col){
        int n = mat.size();
        int m = mat[0].size();
        int colcnt = 0;
        for(int i=0;i<n;i++){
            if(mat[i][col]==1)++colcnt;
        }
        int rowcnt = 0;
        for(int i=0;i<m;i++){
            if(mat[row][i]==1)++rowcnt;
        }
        return colcnt==1&&rowcnt==1;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1&&check(mat,i,j)){
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};