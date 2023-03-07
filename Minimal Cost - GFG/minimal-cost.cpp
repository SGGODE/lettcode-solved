//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& heights, int n, int k) {
        // Code here
      vector<int>dp(n+1);
   dp[0]=0;
   dp[1]=abs(heights[0]-heights[1]);
   for(int i=2;i<=min(n,k);i++){
     int x=INT_MAX;
     for(int j=0;j<i;j++){
       if((abs(heights[i]-heights[j])+dp[j])<x){
         x=abs(heights[i]-heights[j])+dp[j];
       }
     }
     dp[i]=x;
   }
   if(k<n){
    for(int i=k+1;i<n;i++){
     int x=INT_MAX;
     for(int j=(i-k);j<i;j++){
       if((abs(heights[i]-heights[j])+dp[j])<x){
         x=abs(heights[i]-heights[j])+dp[j];
       }
     }
     dp[i]=x;
    }
   }
       return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends