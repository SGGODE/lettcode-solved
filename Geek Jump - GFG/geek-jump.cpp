//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1,0);
        dp[0]=0;
       // int cnt=0;
        dp[1]=abs(height[0]-height[1]);
        for(int i=2;i<n;i++){
            int x=abs(height[i]-height[i-1]);
            int y=abs(height[i]-height[i-2]);
            // if(x==(min(x,y))){
            //     dp[i]=x+dp[i-1];
            // }else if(x==y){
               dp[i]=min(x+dp[i-1],y+dp[i-2]);
            // }
            // else{
            //     dp[i]=y+dp[i-2];
            // }
           // dp[i]=min(x,y);
        }
        //for(auto it:dp)cout<<it<<" "; 
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends