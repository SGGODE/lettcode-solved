class Solution {
private:
    // bool safe(int row,int col,vector<string>&board,int n){
    //     int temprow=row;
    //     int tempcol=col;
    //     while(tempcol>=0){
    //         if(board[row][tempcol]=='Q')return 0;
    //         --tempcol;
    //     }
    //     tempcol=col;
    //     while(temprow>=0&&tempcol>=0){
    //          if(board[temprow][tempcol]=='Q')return 0;
    //         --tempcol;
    //         --temprow;
    //     }
    //     temprow=row;
    //     tempcol=col;
    //     while(temprow<n&&tempcol>=0){
    //          if(board[temprow][tempcol]=='Q')return 0;
    //         --tempcol;
    //         ++temprow;
    //     }
    //     return 1;
    // }
    void solve(int col,vector<string>&board,set<vector<string>>&res,int n,vector<int>&rowcheck,vector<int>&lowerdia,vector<int>&upperdia){
        if(col==n){
            res.insert(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(rowcheck[row]==0&&lowerdia[row+col]==0&&upperdia[n-1+col-row]==0){
                board[row][col]='Q';rowcheck[row]=1;lowerdia[row+col]=1;upperdia[n-1+col-row]=1;
                solve(col+1,board,res,n,rowcheck,lowerdia,upperdia);
                board[row][col]='.';rowcheck[row]=0;lowerdia[row+col]=0;upperdia[n-1+col-row]=0;
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
        vector<int>rowcheck(n,0);
        vector<int>lowerdia(2*n-1,0),upperdia(2*n-1,0);
        solve(0,board,res,n,rowcheck,lowerdia,upperdia);
        return res.size();
    }
};