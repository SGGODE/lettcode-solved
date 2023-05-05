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
    void solve(int col,vector<string>&board,vector<vector<string>>&result,int n){
        if(col==n){
            result.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(safe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,result,n);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<string>res;
        string s(n,'.');
        vector<string>board(n,"");
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,result,n);
        return result;
    }
};