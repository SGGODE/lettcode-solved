class Solution {
private:
    // int mincnt=INT_MAX;
    // void exit(vector<vector<char>>&maze,vector<vector<bool>>&vis,int x,int y,int cnt){
    //     int n=maze.size();int m=maze[0].size();
    //     vis[x][y]=1;
    //     int dx[4]={-1,0,1,0};
    //     int dy[4]={0,1,0,-1};
    //     for(int i=0;i<4;i++){
    //         if((x>=0&&y>=0&&x<n&&y<m)&&maze[x+dx[i]][y+dy[i]]=='.'){
    //             if((x+dx[i]==n-1)||(y+dy[i]==m-1)&&(x==0)&&(y==0)&&maze[x+dx[i]][y+dy[i]]=='.'){
    //                 mincnt=min(mincnt,cnt+1);
    //             }
    //             exit(maze,vis,x+dx[i],y+dy[i],cnt+1);
    //         }
    //     }
    // }
    int n,m;
    bool done(int x,int y){
        return (x==0||x==n-1||y==m-1||y==0);
    }
    bool check(int x,int y){
        return (x<n&&y<m&&x>=0&&y>=0);
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n=maze.size();
        m=maze[0].size();
        maze[entrance[0]][entrance[1]]='+';
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        queue<pair<int,int>>pq;
        int cnt=0;
        pq.push({entrance[0],entrance[1]});
        while(!pq.empty()){
            int size=pq.size();
            for(int i=0;i<size;i++){
                auto node=pq.front();
                int x=node.first;
                int y=node.second;
                pq.pop();
                if(done(x,y)&&maze[x][y]!='+'){
                    return cnt;
                }
                for(int i=0;i<4;i++){
                    int nr=dx[i]+x;int nc=dy[i]+y;
                    if(check(nr,nc)&&maze[nr][nc]=='.'){
                        pq.push({nr,nc});
                        maze[nr][nc]='-00';
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};