class Solution {
private:
    bool check(int row,int col,int dim){
        return row>=0&&col>=0&&col<dim&&row<dim;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1)return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({1,{0,0}});
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        vis[0][0]=1;
        vector<vector<int>>res(n,vector<int>(n,1e9));
        res[0][0]=1;
        int min_cost=INT_MAX;
        while(!pq.empty()){
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            int cost=pq.top().first;
            pq.pop();
            vis[row][col]=1;
            if(row==n-1&&col==n-1){
                min_cost=min(min_cost,cost);
            }
            int dx[8]={0,1,0,-1,-1,1,-1,1};
            int dy[8]={1,0,-1,0,-1,1,1,-1};
            for(int i=0;i<8;i++){
                if(check(row+dx[i],col+dy[i],n)&&grid[row+dx[i]][col+dy[i]]==0&&!vis[row+dx[i]][col+dy[i]]&&res[row+dx[i]][col+dy[i]]>
                  cost+1){
                    res[row+dx[i]][col+dy[i]]=cost+1;
                    pq.push({cost+1,{row+dx[i],col+dy[i]}});
                }
            }
        }
        return min_cost==INT_MAX?-1:min_cost;
    }
};