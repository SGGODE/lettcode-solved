//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    long long int fun(int coins[],int index,int sum,vector<vector<long long int>>&dp){
        if(index==0){
            if(sum%coins[0]==0)return 1;
            return 0;
        }
        if(dp[index][sum]!=-1)return dp[index][sum];
        long long int notpick=fun(coins,index-1,sum,dp);
        long long int pick=0;
        if(sum>=coins[index]){
            pick=fun(coins,index,sum-coins[index],dp);
        }
        return dp[index][sum]=notpick+pick;
    }
  public:
    long long int count(int coins[], int n, int sum) {
         vector<vector<long long int>>dp(n,vector<long long int>(sum+1,-1));
         return fun(coins,n-1,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends