class Solution {
private:
     bool check(vector<vector<char>>& board,int start,int end){
        map<int,int>mapfirst;
        map<int,int>mapsecond;
        map<int,int>mapthired;
        for(int i=start;i<end;i++){
           for(int j=0;j<3;j++){
                if(board[i][j]=='.')continue;
               if(mapfirst.find(board[i][j])!=mapfirst.end()){
                   //cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                   return 0;
               }
               mapfirst[board[i][j]]++;
           } 
           for(int j=3;j<6;j++){
                if(board[i][j]=='.')continue;
               if(mapsecond.find(board[i][j])!=mapsecond.end()){
                  // cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                   return 0;
               }
               mapsecond[board[i][j]]++;
           }
           for(int j=6;j<9;j++){
                if(board[i][j]=='.')continue;
               if(mapthired.find(board[i][j])!=mapthired.end()){
                  // cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                   return 0;
               }
               mapthired[board[i][j]]++;
           }
        }
       return 1; 
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            map<int,int>mp;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(mp.find(board[i][j])!=mp.end()){
                    //cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                    return 0;
                }
                mp[board[i][j]]++;
            }map<int,int>mpcol;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')continue;
                if(mpcol.find(board[j][i])!=mpcol.end()){
                   // cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                    return 0;
                }
                mpcol[board[j][i]]++;
            }
        }
        if(!check(board,0,3)){
            return 0;
        }
        if(!check(board,3,6)){
            return 0;
        }
        if(!check(board,6,9))return 0;
        return 1;
    }
};