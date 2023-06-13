class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>>row,col;
        for(int i=0;i<grid.size();i++){
            vector<int>res;
            for(int j=0;j<grid[0].size();j++){
                res.push_back(grid[i][j]);
            }
            row.push_back(res);
        }
         for(int i=0;i<grid[0].size();i++){
            vector<int>res;
            for(int j=0;j<grid.size();j++){
                res.push_back(grid[j][i]);
            }
            col.push_back(res);
        }
        int cnt=0;
        for(int i=0;i<row.size();i++){
            for(int j=0;j<col.size();j++){
                if(row[i]==col[j])++cnt;
            }
        }
        return cnt;
    }
};