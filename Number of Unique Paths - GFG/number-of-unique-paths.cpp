//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    bool check(int row,int col,int n,int m){
        return row>=0&&col>=0&&row<n&&col<m;
    }
    int check(vector<vector<int>>&dp,int a,int b){
        if(a<0||b<0)return 0;
        if(dp[a][b]!=-1)return dp[a][b];
        return dp[a][b]=check(dp,a-1,b)+check(dp,a,b-1);
    }
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
        dp[0][0]=1;
        dp[0][1]=1;
        dp[1][0]=1;
        if(a<1&&b<1)return dp[a][b];
        check(dp,a,b);
        return dp[a-1][b-1];
        // queue<pair<int,int>>pq;
        // pq.push({0,0});
        // int cnt=0;
        // while(!pq.empty()){
        //     int row=pq.front().first;
        //     int col=pq.front().second;
        //     pq.pop();
        //     if(row==a-1&&col==b-1)++cnt;
        //     if(check(row+1,col,a,b)){
        //         pq.push({row+1,col});
        //     }
        //     if(check(row,col+1,a,b)){
        //         pq.push({row,col+1});
        //     }
        // }
        // return cnt;
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