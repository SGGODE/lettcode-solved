//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    private:
    int n,m;
     bool check(int i,int j){
         return i>=0&&j>=0&&i<n&&j<m;
     }
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
         n=grid.size();
         m=grid[0].size();
        queue<pair<pair<int,int>,int>>pq;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    pq.push({{i,j},0});
                }
                if(grid[i][j]==1){
                    ++cnt;
                }
            }
        }
        int tm=0,infect=0;
        while(!pq.empty()){
            int row=pq.front().first.first;
            int col=pq.front().first.second;
            int time=pq.front().second;
            tm=max(tm,time);
            pq.pop();
            vector<int>dx{-1,0,1,0};
            vector<int>dy{0,1,0,-1};
           for(int i=0;i<4;i++){
            if(check(row+dx[i],col+dy[i])&&grid[row+dx[i]][col+dy[i]]==1){
               grid[row+dx[i]][col+dy[i]]=2;
                ++infect;
               pq.push({{row+dx[i],col+dy[i]},time+1});
            }
          }
        }
        if(infect!=cnt)return -1;
        return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends