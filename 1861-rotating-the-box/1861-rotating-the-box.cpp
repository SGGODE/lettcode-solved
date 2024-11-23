class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>>result(m,vector<char>(n,'.'));
        for(int i = 0; i < n; i++){
            deque<pair<int,int>>dq;
            for(int j = m-1; j >= 0; j--){
                if(box[i][j] == '*')dq.clear();
                else if(box[i][j] == '.')dq.push_back({i,j});
                else if(!dq.empty()){
                    box[dq.front().first][dq.front().second] = '#';
                    dq.pop_front();
                    box[i][j] = '.';
                    dq.push_back({i,j});
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                result[j][n-i-1] = box[i][j];
                //cout<<box[i][j]<<" ";
            }//cout<<endl;
        }
        return result;
    }
};