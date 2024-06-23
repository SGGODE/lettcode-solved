class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        vector<int>row , col;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        sort(row.begin(),row.end());
        sort(col.begin(),col.end());
        int e = row.size();
        return ((row[e-1]-row[0])+1)*((col[e-1]-col[0])+1);
    }
};