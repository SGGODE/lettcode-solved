class Solution {
private:
    int n,m;
    bool check(int row,int col){
        return row>=0&&col>=0&&row<n&&col<m;
    }
    void sub(vector<vector<int>>&land,int&row,int&col){
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        land[row][col]=0;
        queue<pair<int,int>>pq;
        pq.push({row,col});
        while(!pq.empty()){
            int r = pq.front().first;
            int c = pq.front().second;
            pq.pop();
            row = max(row,r);
            col = max(col,c);
            for(int i=0;i<4;i++){
                if(check(r+dx[i],c+dy[i])&&land[dx[i]+r][dy[i]+c]==1){
                    land[dx[i]+r][dy[i]+c]=0;
                    pq.push({dx[i]+r,dy[i]+c});
                }
            }
        }
    }
    
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    int row = i,col=j;
                    sub(land,row,col);
                    res.push_back({i,j,row,col});
                }
            }
        }
        return res;
    }
};