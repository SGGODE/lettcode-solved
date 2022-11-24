class Solution {
private:
    int n,m;
    bool check(int i,int j){
        return (i>=0 && j>=0 && i<n &&j<m);
    }
    bool dfs(int i,int j,vector<vector<char>>&board,vector<vector<bool>>&vis,string&s,int index){
      //  if(vis[i][j]){
        //        return false;
//         }vis[i][j]=1;
//         if(index==s.size())return 1;
//         int dx[4]={-1,1,0,0};
//         int dy[4]={0,0,-1,1};
//         int cnt=0;
//         for(int i=0;i<4;i++){
//             int nr=i+dx[i];
//             int nc=j+dy[i];
//             if(check(nr,nc)&&board[nr][nc]==s[index+1]&&!vis[nr][nc]){
//                 ++index;
//                 dfs(nr,nc,board,vis,s,index);
//                 //x.push_back(s[index+1]);
//             }
//            //f(i==3)return 0;
//         }
        
     // return 1;
       // return 0;
        // if(index==s.size())return 1;
        // if(!check(i,j))return 0;
        // if(board[i][j]=='.'&&!check(i,j))return 0;
        // if(board[i][j]!=s[index])return 0;
        // char ch=board[i][j];
        // board[i][j]='.';
        // if(dfs(i+1,j,board,s,index+1,x) or dfs(i-1,j,board,s,index+1,x) or dfs(i,j+1,board,s,index+1,x) or dfs(i,j-1,board,s,index+1,x)) return 1;
        // board[i][j]=ch;
        // return 0;
        if(index==s.size())return 1;
        if(i<0||j<0||i>=n||j>=m||board[i][j]!=s[index])return 0;
        vis[i][j]=1;
        char ch=board[i][j];
        board[i][j]=' ';
       if(dfs(i+1,j,board,vis,s,index+1) or 
          dfs(i-1,j,board,vis,s,index+1) or 
          dfs(i,j+1,board,vis,s,index+1) or 
          dfs(i,j-1,board,vis,s,index+1))return 1;
       
       vis[i][j]=0;
        board[i][j]=ch;
          return 0;
 //   return 0;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
         n=board.size();
         m=board[0].size();
         vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && dfs(i,j,board,vis,word,0)){
                        return 1;
                }
            }
    }
        return 0;
    }
};