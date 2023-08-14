class Solution {
    bool check(int row,int col,int n,int m){
    return row>=0&&col>=0&&row<n&&col<m;
}

public:
    int minimumEffortPath(vector<vector<int>>&matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,1e9));
    dp[0][0]=matrix[0][0];
    queue<pair<pair<int,int>,int>>pq;
    pq.push({{0, 0},0});
    int dx[4]={-1,0,+1,0};
    int dy[4]={0,-1,0,+1};
    int res=INT_MAX;
    while(!pq.empty()){
        int row=pq.front().first.first;
        int col=pq.front().first.second;
        int diff=pq.front().second;
         pq.pop();
        if (row == n - 1 && col == m - 1) {
          res = min(res, diff);
          continue;
        }
        for(int i=0;i<4;i++){
            if(check(row+dx[i],col+dy[i],n,m)&&dp[row+dx[i]][col+dy[i]]>max(diff,abs(matrix[row+dx[i]][col+dy[i]]-matrix[row][col]))){
                dp[row+dx[i]][col+dy[i]]=max(diff,abs(matrix[row+dx[i]][col+dy[i]]-matrix[row][col]));
                pq.push({{row+dx[i],col+dy[i]},max(diff,abs(matrix[row+dx[i]][col+dy[i]]-matrix[row][col]))});
            }
        }
    }
    return res;
    }
};