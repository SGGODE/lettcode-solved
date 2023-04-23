//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
   int fun(int val[],int wt[],int index,int W,vector<vector<int>>&dp){
       if(index==0){
         return (val[0])*(W/wt[index]);
           //return 0;
       }
       if(dp[index][W]!=-1)return dp[index][W];
       int nottake=0+fun(val,wt,index-1,W,dp);
       int take=INT_MIN;
       if(wt[index]<=W){
           take=val[index]+fun(val,wt,index,W-wt[index],dp);
       }
       return dp[index][W]=max(take,nottake);
   }
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return fun(val,wt,n-1,W,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends