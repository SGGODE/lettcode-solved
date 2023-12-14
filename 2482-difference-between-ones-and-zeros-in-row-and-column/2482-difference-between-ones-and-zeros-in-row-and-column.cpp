class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        map<int,pair<int,int>>row,col;
        for(int i=0;i<grid.size();i++){
            int z = 0,o = 0;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)++o;
                else z++;
            }
            row[i]={o,z};
        }
        for(int i=0;i<grid[0].size();i++){
            int z = 0,o = 0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1)++o;
                else z++;
            }
            col[i]={o,z};
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>diff(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int onesRow = row[i].first;
                int onesCol = col[j].first;
                int zeroRow = row[i].second;
                int zeroCol = col[j].second;
                diff[i][j]=((onesRow+onesCol)-(zeroRow+zeroCol));
            }
        }
        return diff;
    }
};