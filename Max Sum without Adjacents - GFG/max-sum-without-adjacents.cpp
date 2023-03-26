//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	     if(n==1)return arr[0];
        vector<int>dp(n,0);
        dp[0]=arr[0];
       // dp[1]=arr[1];
        priority_queue<pair<int,int>>pq;
        pq.push({arr[0],0});
        pq.push({arr[1],1});
        for(int i=1;i<n;i++){
            // int m=INT_MIN; priority_queue<pair<int,int>>px(pq);
            // while(!px.empty()&&px.top().second == i-1){
            //     px.pop();
            // }
            // dp[i]=arr[i]+px.top().first;
            // pq.push({dp[i],i});
            int curr=arr[i];
            if(i>1){
                curr+=dp[i-2];
            }
            int miss=dp[i-1];
            dp[i]=max(curr,miss);
        }
      //  cout<<dp[n-1]<<endl;
        return dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends