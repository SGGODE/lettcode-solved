class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        //int n=grid.size();
        int n=grid.size();
        int m=grid[0].size();
         vector<int>res(m,0);
        for(int i=0;i<n;i++){
          //  int ans=INT_MIN;
            for(int j=0;j<m;j++){
                int t=to_string(grid[i][j]).length();
                //ans=max(ans,t);
                res[j]=max(res[j],t);
            }
          //  res.push_back(ans);
        }
        return res;
    }
};