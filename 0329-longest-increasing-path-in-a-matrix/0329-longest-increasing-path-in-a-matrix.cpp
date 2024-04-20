class Solution {
private:
    int n,m;
    int dp[201][201];
    bool check(int row,int col){
        return row>=0&&col>=0&&row<n&&col<m;
    }
    int sub(vector<vector<int>>&matrix,int row,int col){
        if(dp[row][col]!=-1)return dp[row][col];
        int ans = 0;
        if(check(row+1,col)&&matrix[row+1][col]>matrix[row][col])ans = max(ans,1+sub(matrix,row+1,col));
        if(check(row-1,col)&&matrix[row-1][col]>matrix[row][col])ans = max(ans,1+sub(matrix,row-1,col));
        if(check(row,col+1)&&matrix[row][col+1]>matrix[row][col])ans = max(ans,1+sub(matrix,row,col+1));
        if(check(row,col-1)&&matrix[row][col-1]>matrix[row][col])ans = max(ans,1+sub(matrix,row,col-1));
        return dp[row][col]=ans;
    }
    // int sub(vector<vector<int>>matrix,int row,int col,int n,int m){
    //     int dx[4]={0,0,1,-1};
    //     int dy[4]={1,-1,0,0};
    //     queue<pair<pair<int,int>,int>>pq;
    //     int len = 0;
    //     pq.push({{row,col},1});
    //     while(!pq.empty()){
    //         auto it = pq.front();
    //         int val = it.second;
    //         int r = it.first.first;
    //         int c = it.first.second;
    //         len = max(len,val);
    //         pq.pop();
    //         for(int i=0;i<4;i++){
    //             if(check(r+dx[i],c+dy[i],n,m)&&matrix[r][c]<matrix[r+dx[i]][c+dy[i]]){
    //                pq.push({{r+dx[i],c+dy[i]},val+1});
    //             }
    //         }
    //     }
    //     return len;
    // }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,1+sub(matrix,i,j));
                //dp[i][j]=ans;
            }
        }
        return ans;
    }
};