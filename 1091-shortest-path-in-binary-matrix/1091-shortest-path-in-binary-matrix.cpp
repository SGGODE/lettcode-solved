class Solution {
private:
    int n,m;
    bool check(int row,int col){
        return row>=0&&col>=0&&row<n&&col<m;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(grid[0][0]==1)return -1;
        queue<pair<pair<int,int>,int>>pq;
        pq.push({{0,0},1});
        int dx[8]={0,1,0,-1,-1,-1,1,1};
        int dy[8]={1,0,-1,0,-1,1,-1,1};
        int minstep=INT_MAX;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        vector<vector<int>>res(n,vector<int>(m,1e8));
        res[0][0]=1;
        while(!pq.empty()){
            int row=pq.front().first.first;
            int col=pq.front().first.second;
            int dist=pq.front().second;
            pq.pop();
            vis[row][col]=1;
            if(row==n-1&&col==m-1){
                minstep=min(minstep,dist);
                continue;
            }
            for(int i=0;i<8;i++){
                if(check(row+dx[i],col+dy[i])&&grid[row+dx[i]][col+dy[i]]==0&&!vis[row+dx[i]][col+dy[i]]&&res[row+dx[i]][col+dy[i]]>(res[row][col]+1)){         res[row+dx[i]][col+dy[i]]=res[row][col]+1;
                    pq.push({{row+dx[i],col+dy[i]},dist+1});
                }
            }
        }
        return minstep==INT_MAX?-1:minstep;
    }
};