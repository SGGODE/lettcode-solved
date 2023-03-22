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
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	     n=grid.size();
	     m=grid[0].size();
	    vector<vector<int>>dist(n,vector<int>(m,0));
	    vector<vector<bool>>vis(n,vector<bool>(m,0));
	    queue<pair<pair<int,int>,int>>pq;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                pq.push({{i,j},0});
	                vis[i][j]=1;
	            }
	        }
	    }
	    while(!pq.empty()){
	        int row=pq.front().first.first;
	        int col=pq.front().first.second;
	        int distance=pq.front().second;
	        pq.pop();
	        dist[row][col]=distance;
	        int dx[4]={-1,0,1,0};
	        int dy[4]={0,1,0,-1};
	        for(int i=0;i<4;i++){
	            if(check(row+dx[i],col+dy[i])&&!vis[row+dx[i]][col+dy[i]]&&grid[row+dx[i]][col+dy[i]]==0){
	                vis[row+dx[i]][col+dy[i]]=1;
	                pq.push({{row+dx[i],col+dy[i]},distance+1});
	            }
	        }
	    }
	    return dist;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends