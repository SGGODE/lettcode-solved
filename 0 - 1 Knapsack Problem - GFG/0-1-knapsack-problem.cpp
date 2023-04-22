//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // static bool comp(pair<int,int> s,pair<int,int>r){
    //     if(s.second==r.second)
    //      return s.first < r.first;
    //     return s.second < r.second;
    // }
    int maxsum=INT_MIN;
    // int sub(int sum,int index,int n,int W,int wt[],int val[],vector<vector<int>>&dp){
    //   // if(W==0)return 1;
    //     if(index==0){
    //         if(W>=wt[0])return val[0];
    //         return 0;
    //     }
    //   if(dp[index][W]!=-1)return dp[index][W];
    //     int notpick=0+sub(sum,index-1,n,W,wt,val,dp);
    //     int pick=INT_MIN;
    //     if(W>=wt[index]){
    //         pick=val[index]+sub(sum,index-1,n,W-wt[index],wt,val,dp);
    //     }
    //     return dp[index][W]=max(pick,notpick);
    // }
    // int sub(int sum,int index,int n,int W,int wt[],int val[],vector<vector<int>>&dp){
    //   // if(W==0)return 1;
    //     if(index==0){
    //       if(W>=wt[0])return sum+val[0];
    //       return sum;
    //     }
    //   //if(dp[index][W]!=-1)return dp[index][W];
    //     int notpick=0+sub(sum,index-1,n,W,wt,val,dp);
    //     int pick=INT_MIN;
    //     if(W>=wt[index]){
    //         pick=sub(sum+val[index],index-1,n,W-wt[index],wt,val,dp);
    //     }
    //     return max(pick,notpick);
    // }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int sum=0;
       for(int i=0;i<n;i++)sum+=val[i];
       vector<vector<int>>dp(n,vector<int>(W+1,0));
       for(int i=wt[0];i<=W;i++){
           dp[0][i]=val[0];
       }
       for(int i=1;i<n;i++){
           for(int j=0;j<=W;j++){
               int notpick=0+dp[i-1][j];
               int pick=INT_MIN;
               if(j>=wt[i]){
                   pick=val[i]+dp[i-1][j-wt[i]];
               }
               dp[i][j]=max(notpick,pick);
           }
       }
       return dp[n-1][W];
      //return sub(0,n-1,n,W,wt,val,dp);
       //return maxsum;
     //  return dp[n-2][sum];
    //   int m=INT_MIN;
    //   for(int i=0;i<res.size();i++){
    //       int sum=0;
    //       for(auto it:res[i]){
    //           sum+=it.first;
    //       }
    //       m=max(m,sum);
    //   }
    //   sort(v.begin(),v.end());
    //   int m=INT_MIN;
    //  //  int n=val.size();
    //   for(int i=n-1;i>=0;i--){
    //       if(v[i].second <= W){
    //         //   int sum=v[i].first;
    //          int currw=v[i].second;
    //         int max_profit=0;
    //           for(int j=i-1;j>=0;j--){
    //             if(j==i)continue;
    //               if(v[j].second+currw <= W){
    //                   max_profit=max(max_profit,v[i].first);
    //               }
    //           }
    //           m=max(m,v[i].first+max_profit);
    //       }
    //   }
    //   return m;
    //return m;
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends