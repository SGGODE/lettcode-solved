class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0 ; i <= n-3 ; i++){
           for(int j = 0 ; j <= m-3 ; j++){
               unordered_map<int,int>mp,sumdp;
                bool flag = 0;
               int sum = 0;
               int rsum = 0 , csum = 0;
               for(int k = i ; k < i+3 ; k++){
                   for(int l = j ; l < j+3 ; l++){
                       mp[grid[k][l]]++;
                       rsum+=grid[k][l];
                       if(grid[k][l] > 9 || grid[k][l] < 1)flag = 1;
                   }
                   sumdp[rsum]++;
                   rsum = 0;
               }
               for(int k = j ; k < j+3 ; k++){
                   for(int l = i ; l < i+3 ; l++){
                       csum+=grid[l][k];
                   }
                   sumdp[csum]++;
                   csum = 0;
               }
               int dsum1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
               int dsum2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
               if(mp.size() == 9 && sumdp.size() == 1 && !flag && dsum1 == dsum2)++count;   
           }
        }
        return count;
    }
};