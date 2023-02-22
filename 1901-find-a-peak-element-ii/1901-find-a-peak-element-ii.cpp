class Solution {
private:
    bool check(vector<vector<int>>& mat,int n,int m,int i,int j,int sum){
        bool flag1=0,flag2=0,flag3=0,flag=0;;
       // if(1){
            if(((i+1)<n&&j<m&&mat[i+1][j]<sum)||((i+1)>=n)){
                flag=1;
            }
            if(((i-1)>=0&&j<m&&mat[i-1][j]<sum)||((i-1)<0)){
                flag1=1;
            }
            if(((j+1)<m&&i<n&&mat[i][j+1]<sum)||((j+1)>=m)){
                flag2=1;
            }
            if(((j-1)>=0&&i<n&&mat[i][j-1]<sum)||((j-1)<0)){
                flag3=1;
            }
       // }
        return flag&&flag1&&flag3&&flag2;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(mat,n,m,i,j,mat[i][j])){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};