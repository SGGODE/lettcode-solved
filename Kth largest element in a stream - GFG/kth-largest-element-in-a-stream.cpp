//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        // sort(arr,arr+n);
         vector<int>v;
        // if(k>1){
        //   for(int i=0;i<k-1;i++){
        //      v[i]=-1;
        //   }int j=0;
        //   for(int i=k-1;i<n;i++){
        //       v[i]=arr[j++];
        //   }
        // }else{
        //     for(int i=0;i<n;i++){
        //         v[i]=arr[i];
        //     }
        // }
        // return v;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k)pq.pop();
            if(pq.size()<k)v.push_back(-1);
            else{
                v.push_back(pq.top());
            }
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends