//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    bool check(int row,int col,int n){
        return row>=0&&col>=0&&row<n&&col<n;
    }
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        //code here
        int n=grid.size();
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)vis[i][j]=1;
                if(grid[i][j]==1){
                    pq.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        while(!pq.empty()){
            int row=pq.front().first;
            int col=pq.front().second;
            pq.pop();
            if(grid[row][col]==2)return 1;
            vis[row][col]=1;
            for(int i=0;i<4;i++){
                if(check(row+dx[i],col+dy[i],n)&&!vis[row+dx[i]][col+dy[i]]){
                    pq.push({row+dx[i],col+dy[i]});
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends