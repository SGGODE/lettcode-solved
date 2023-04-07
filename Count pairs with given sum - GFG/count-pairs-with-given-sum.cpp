//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
         sort(arr,arr+n);
        //int sum=0;
        int cnt=0;
        map<int,int>mp;
        for(int i=0;i<n;i++)mp[arr[i]]++;
        for(int i=0;i<n;i++){
           int sum=k-arr[i];
           --mp[arr[i]];
           if(mp[arr[i]]==0)mp.erase(arr[i]);
           if(mp.count(sum))cnt+=mp[sum];
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends