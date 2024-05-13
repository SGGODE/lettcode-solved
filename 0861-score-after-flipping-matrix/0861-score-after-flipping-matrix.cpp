class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = (1<<(m-1))*n;
        for(int i=1;i<m;i++) {
            int curr=0;
            for(int j=0;j<n;j++) {
                if(grid[j][i]==grid[j][0])curr++;
            }
            res += (1<<(m-i-1))*max(curr, n-curr);
        }
        return res;
    }
};