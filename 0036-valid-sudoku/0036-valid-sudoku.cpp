class Solution {
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
        map<int,int>mapfirst;
        map<int,int>mapsecond;
        map<int,int>mapthired;
        for(int i=0;i<3;i++){
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
        map<int,int>mapfour;
        map<int,int>mapfive;
        map<int,int>mapsix;
        for(int i=3;i<6;i++){
           for(int j=0;j<3;j++){
                if(board[i][j]=='.')continue;
               if(mapfour.find(board[i][j])!=mapfour.end()){
                   //cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                   return 0;
               }
               mapfour[board[i][j]]++;
           } 
           for(int j=3;j<6;j++){
                if(board[i][j]=='.')continue;
               if(mapfive.find(board[i][j])!=mapfive.end()){
                  // cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                   return 0;
               }
               mapfive[board[i][j]]++;
           }
           for(int j=6;j<9;j++){
                if(board[i][j]=='.')continue;
               if(mapsix.find(board[i][j])!=mapsix.end()){
                  // cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                   return 0;
               }
               mapsix[board[i][j]]++;
           }
        }
        map<int,int>mapseven;
        map<int,int>mapeight;
        map<int,int>mapnine;
        for(int i=6;i<9;i++){
           for(int j=0;j<3;j++){
                if(board[i][j]=='.')continue;
               if(mapseven.find(board[i][j])!=mapseven.end()){
                   //cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                   return 0;
               }
               mapseven[board[i][j]]++;
           } 
           for(int j=3;j<6;j++){
                if(board[i][j]=='.')continue;
               if(mapeight.find(board[i][j])!=mapeight.end()){
                  // cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                   return 0;
               }
               mapeight[board[i][j]]++;
           }
           for(int j=6;j<9;j++){
                if(board[i][j]=='.')continue;
               if(mapnine.find(board[i][j])!=mapnine.end()){
                  // cout<<i<<" "<<j<<" "<<board[i][j]<<endl;
                   return 0;
               }
               mapnine[board[i][j]]++;
           }
        }
        return 1;
    }
};