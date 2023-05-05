class Solution {
private:
    bool safe(int row,int col,vector<string>&board,int n){
        int temprow=row;
        int tempcol=col;
        while(tempcol>=0){
            if(board[row][tempcol]=='Q')return 0;
            --tempcol;
        }
        tempcol=col;
        while(temprow>=0&&tempcol>=0){
             if(board[temprow][tempcol]=='Q')return 0;
            --tempcol;
            --temprow;
        }
        temprow=row;
        tempcol=col;
        while(temprow<n&&tempcol>=0){
             if(board[temprow][tempcol]=='Q')return 0;
            --tempcol;
            ++temprow;
        }
        return 1;
    }
    void solve(int col,vector<string>&board,set<vector<string>>&res,int n){
        if(col==n){
            res.insert(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(safe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,res,n);
                board[row][col]='.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<string>board(n,"");
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        set<vector<string>>res;
        solve(0,board,res,n);
        return res.size();
    }
};