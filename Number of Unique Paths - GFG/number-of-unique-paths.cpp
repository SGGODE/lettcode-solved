//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution{
    private:
    bool check(int row,int col,int n,int m){
        return row>=0&&col>=0&&row<n&&col<m;
    }
    int dfs(vector<vector<int>>&dp,int row,int col,int n,int m){
        if(row==n-1&&col==m-1)return 1;
        if(dp[row][col]!=-1)return dp[row][col];
        int down=0;
        int right=0;
        if(check(row+1,col,n,m))down=dfs(dp,row+1,col,n,m);
        if(check(row,col+1,n,m))right=dfs(dp,row,col+1,n,m);
        return dp[row][col]=down+right;
    }
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
       // int cnt=0;
       // queue<pair<int,int>>pq;
        vector<vector<int>>dp(a,vector<int>(b,-1));
        return dfs(dp,0,0,a,b);
        // pq.push({0,0});
        // while(!pq.empty()){
        //     int row=pq.front().first;
        //     int col=pq.front().second;
        //     pq.pop();
        //     if(row==a-1&&col==b-1)++cnt;
        //     if(check(row+1,col,a,b))pq.push({row+1,col});
        //     if(check(row,col+1,a,b))pq.push({row,col+1});
        // }
        //return dp[a-1][b-1];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends