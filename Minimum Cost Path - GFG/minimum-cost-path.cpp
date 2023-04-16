//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int n,m;
    bool check(int row,int col){
        return row>=0&&col>=0&&row<n&&col<m;
    }
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
// 	int findpath(vector<vector<int>>&grid,vector<vector<int>>&dp,int row,int col){
// 	    if(row==0&&col==0)return grid[row][col];
// 	     if(row<0||col<0)return INT_MAX;
// 	    if(dp[row][col]!=-1)return dp[row][col];
// 	   // int left=INT_MAX,right=INT_MAX,up=INT_MAX,down=INT_MAX;
// 	    int left=findpath(grid,dp,row-1,col);
// 	    int right=findpath(grid,dp,row,col-1);
// 	    int up=findpath(grid,dp,row+1,col);
// 	    int down=findpath(grid,dp,row,col+1);
// 	   ////int dx[4]={0,1,0,-1};
// 	   //int dy[4]={-1,0,1,0};
// 	   //int min_cost=INT_MAX;
// 	   //for(int i=0;i<4;i++){
// 	   //    if(check(row+dx[i],col+dy[i])){
// 	   //      //  int total=
// 	   //        min_cost=min(min_cost,findpath(grid,dp,row+dx[i],col+dy[i]));
// 	   //    }
// 	   //}
// 	    return dp[row][col]=grid[row][col]+min(left,min(right,min(up,down)));
// 	}
    int pathsum(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j,int n,int m){  
        if(!check(i,j))return INT_MAX;
        if(i==0&&j==0){
           return grid[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int up=pathsum(grid,dp,i-1,j,n,m);
        int left=pathsum(grid,dp,i,j-1,n,m);
        int down=pathsum(grid,dp,i+1,j,n,m);
        int right=pathsum(grid,dp,i,j+1,n,m);
        return dp[i][j]=grid[i][j]+min(min(up,left),min(down,right));
    }
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        int dx[4]={0,1,0,-1};
        int dy[4]={-1,0,1,0};
        while(!pq.empty()){
            int dist=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                if(check(row+dx[i],col+dy[i])&&dp[row+dx[i]][col+dy[i]]>dist+grid[row+dx[i]][col+dy[i]]){
                    dp[row+dx[i]][col+dy[i]]=dist+grid[row+dx[i]][col+dy[i]];
                    pq.push({dist+grid[row+dx[i]][col+dy[i]],{row+dx[i],col+dy[i]}});
                }
            }
        }
        //return pathsum(grid,dp,n-1,m-1,n,m);
       // return findpath(grid,dp,n-1,m-1);
        return dp[n-1][m-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends