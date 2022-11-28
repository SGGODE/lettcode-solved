class Solution {
private:
    int n,m;
    int countrowone(vector<vector<int>>& grid,int i,int j){
        int cnt=0;
        for(int k=0;k<m;k++){
            if(grid[i][k]==1)cnt++;
        }
        return cnt;
    }
    int countcolone(vector<vector<int>>& grid,int i,int j){
        int cnt=0;
        for(int k=0;k<n;k++){
            if(grid[k][j]==1)cnt++;
        }
        return cnt;
    }
    int countrowzero(vector<vector<int>>& grid,int i,int j){
          int cnt=0;
        for(int k=0;k<m;k++){
            if(grid[i][k]==0)cnt++;
        }
        return cnt;
    }
    int countcolzero(vector<vector<int>>& grid,int i,int j){
          int cnt=0;
        for(int k=0;k<n;k++){
            if(grid[k][j]==0)cnt++;
        }
        return cnt;
    }
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        vector<int>rowone(n),colone(m),rowzero(n),colzero(m);
        vector<vector<int>>diff(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            int zero=0,one=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)zero++;
                else one++;
            }
            rowone[i]=one;
            rowzero[i]=zero;
        }
        for(int i=0;i<m;i++){
            int zero=0,one=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==0)zero++;
                else one++;
            }
            colone[i]=one;
            colzero[i]=zero;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                diff[i][j] =rowone[i]+colone[j]-rowzero[i]-colzero[j];
            }
        }
        return diff;
    }
};