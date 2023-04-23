//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int fun(int price[],int index,int n,vector<vector<int>>&dp){
        if(index==0){
            if(n>=1)return price[0]*n;
            return 0;
        }
        if(dp[index][n]!=-1)return dp[index][n];
        int nottake=0+fun(price,index-1,n,dp);
        int take=INT_MIN;
        if(index+1<=n){
            take=price[index]+fun(price,index,n-(index+1),dp);
        }
        return dp[index][n]=max(nottake,take);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        int sum=0;
        for(int i=0;i<n;i++)sum+=price[i];
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return fun(price,n-1,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends