class Solution {
private:
    int n,m;
    bool check(int row,int col){
        return row>=0&&col>=0&&row<n&&col<m;
    }
    void sub(vector<vector<char>>&grid, vector<vector<int>>&vis,int row,int col){
        queue<pair<int,int>>pq;
        pq.push({row,col});
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!pq.empty()){
            int r = pq.front().first;
            int c = pq.front().second;
            pq.pop();
            vis[r][c]=1;
            for(int i=0;i<4;i++){
                if(check(dx[i]+r,dy[i]+c)&&!vis[dx[i]+r][dy[i]+c]&&grid[dx[i]+r][dy[i]+c]=='1'){
                    vis[dx[i]+r][dy[i]+c]=1;
                    pq.push({dx[i]+r,dy[i]+c});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    ++cnt;
                    sub(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};