//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
private:
   int combination(int prices[],vector<vector<int>>&dp,int sum,int index){
       if(sum==0)return 0;
       if(index==0){
           return sum*prices[0];
       }
       if(dp[index+1][sum]!=-1)return dp[index+1][sum];
       int notpick=combination(prices,dp,sum,index-1);
       int pick=0;
       if(sum>=index+1){
           pick=prices[index]+combination(prices,dp,sum-(index+1),index);
       }
       return dp[index+1][sum]=max(pick,notpick);
   }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return combination(price,dp,n,n-1);
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