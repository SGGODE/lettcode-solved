class Solution {
private:
    int n,m;
    bool check(int row,int col){
        return row>=0&&row<n&&col>=0&&col<m;
    }
    int division(vector<vector<int>>&img,int row,int col){
        int dx[8]={0,0,1,-1,-1,-1,1,1};
        int dy[8]={-1,1,0,0,-1,1,-1,1};
        int cnt = 1;
        int sum = img[row][col];
        for(int i=0;i<8;i++){
            if(check(row+dx[i],col+dy[i])){
                ++cnt;
                sum += img[row+dx[i]][col+dy[i]];
            }
        }
        return floor(sum/cnt);
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
         n = img.size();
         m = img[0].size();
        vector<vector<int>>res(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j] = division(img,i,j);
            }
        }
        return res;
    }
};