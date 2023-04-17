class Solution {
private:
    bool check(int row,int col,int n,int m){
        return row>=0&&col>=0&&row<n&&col<m;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        for(int i=1;i<n;i++){
            int ans=INT_MAX;int m=triangle[i].size();
            for(int j=0;j<m;j++){
                int curr=INT_MAX;
                if(check(i-1,j,n,m-1))curr=min(curr,triangle[i][j]+triangle[i-1][j]);
                if(check(i-1,j-1,n,m-1))curr=min(curr,triangle[i][j]+triangle[i-1][j-1]);
                triangle[i][j]=curr;
            }
        }
        return *min_element(triangle[n-1].begin(),triangle[n-1].end());
    }
};