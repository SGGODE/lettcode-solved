class Solution {
private:
    int n,m;
    bool ingrid(int row,int col){
        return row>=0&&col>=0&&row<n&&col<m;
    }
    bool check(vector<vector<char>>& board,int row,int col, string word,int index){
         if(index==word.size())return 1;
         if(!ingrid(row,col)||word[index]!=board[row][col])return 0;
         char ch = board[row][col];
         board[row][col]=' ';
         
         if(check(board,row+1,col,word,index+1) or check(board,row-1,col,word,index+1) or 
           check(board,row,col+1,word,index+1) or check(board,row,col-1,word,index+1))return 1;
        
         board[row][col]=ch;
         return 0;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(check(board,i,j,word,0))return 1;
                }
            }
        }
        return 0;
    }
};