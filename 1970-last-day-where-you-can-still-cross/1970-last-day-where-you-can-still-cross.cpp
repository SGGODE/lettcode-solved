class Solution {
private:
    int n,m;
    bool check(int row,int col){
        return row>=0&&col>=0&&row<n&&col<m;
    }
    bool bfs(vector<vector<int>>& cells,int mid){
        queue<pair<int,int>>pq;
         vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<mid;i++){
                vis[cells[i][0]-1][cells[i][1]-1]=1;
        }
         for(int i=0;i<m;i++){
            if(!vis[0][i]){
                pq.push({0,i});
                vis[0][i]=1;
            }
        }
        int dx[4]={0,-1,0,1};
        int dy[4]={1,0,-1,0};
        while(!pq.empty()){
           int row1=pq.front().first;
            int col1=pq.front().second;
            pq.pop();
            if(row1==n-1){
                return 1;
            }
            for(int i=0;i<4;i++){
                if(check(row1+dx[i],col1+dy[i])&&!vis[row1+dx[i]][col1+dy[i]]){
                         vis[row1+dx[i]][col1+dy[i]]=1;
                        pq.push({row1+dx[i],col1+dy[i]});
                }
            }
        }
        return 0;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n=row;
        m=col;
        vector<vector<bool>>vis(row,vector<bool>(col,0));
        int result=0;
        int l=cells.size();
        // for(int i=0;i<cells.size();i++){
        //     vis[cells[i][0]-1][cells[i][1]-1]=1;
        //     vector<vector<bool>>temp(vis);
        //     queue<pair<int,int>>pq;
        //     for(int i=0;i<col;i++){
        //         if(!vis[0][i])pq.push({0,i});
        //     }
        //     bool flag=0;
        //     int dx[4]={0,-1,0,1};
        //     int dy[4]={1,0,-1,0};
        //     while(!pq.empty()){
        //         int row1=pq.front().first;
        //         int col1=pq.front().second;
        //         pq.pop();
        //         if(row1==row-1){
        //             result=i+1;
        //             flag=1;
        //             continue;
        //         }
        //         temp[row1][col1]=1;
        //         for(int i=0;i<4;i++){
        //             if(check(row1+dx[i],col1+dy[i])&&!temp[row1+dx[i]][col1+dy[i]]){
        //                 pq.push({row1+dx[i],col1+dy[i]});
        //             }
        //         }
        //     }
        //     if(flag==0)break;
        // }
        // return result;
        int start=1;
        int end=l;
        int res=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(bfs(cells,mid)){
                res=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return res;
    }
};