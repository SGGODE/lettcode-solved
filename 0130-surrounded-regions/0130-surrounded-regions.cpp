class Solution {
private:
    int n,m;
    bool check(int i,int j){
        return i>=0&&j<m&&j>=0&&i<n;
    }
    bool left(vector<vector<char>>& board,int i,int j){
        for(int k=0;k<j;k++){
            if(board[i][k]=='X')return 1;
        }
        return 0;
    }
    bool right(vector<vector<char>>& board,int i,int j){
       for(int k=j+1;k<m;k++){
            if(board[i][k]=='X')return 1;
        }
        return 0; 
    }
    bool top(vector<vector<char>>& board,int i,int j){
        for(int k=0;k<i;k++){
            if(board[k][j]=='X')return 1;
        }
        return 0;
    }
    bool down(vector<vector<char>>& board,int i,int j){
        for(int k=i+1;k<n;k++){
            if(board[k][j]=='X')return 1;
        }
        return 0;
    }
public:
    void solve(vector<vector<char>>& board) {
         n=board.size();
         m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        queue<pair<int,int>>pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<1;j++){
                if(board[j][i]=='O'){
                    pq.push({j,i});
                    vis[j][i]=1;
                }
            }
             for(int j=n-1;j<n;j++){
                if(board[j][i]=='O'){
                    pq.push({j,i});
                    vis[j][i]=1;
                }
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<1;j++){
                if(board[i][j]=='O'){
                    pq.push({i,j});
                    vis[i][j]=1;
                }
            }
             for(int j=m-1;j<m;j++){
                if(board[i][j]=='O'){
                    pq.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        while(!pq.empty()){
            int row=pq.front().first;
            int col=pq.front().second;
            int dx[4]={1,0,-1,0};
            int dy[4]={0,1,0,-1};
            pq.pop();
            for(int i=0;i<4;i++){
                if(check(row+dx[i],col+dy[i])&&board[row+dx[i]][col+dy[i]]=='O'&&!vis[row+dx[i]][col+dy[i]]){
                    vis[row+dx[i]][col+dy[i]]=1;
                    pq.push({row+dx[i],col+dy[i]});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&left(board,i,j)&&right(board,i,j)&&
                  top(board,i,j)&&down(board,i,j)&&!vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};