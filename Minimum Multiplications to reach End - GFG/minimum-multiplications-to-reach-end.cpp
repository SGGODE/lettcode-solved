//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
    int mod=100000;
    int min_step=INT_MAX;
       queue<pair<int,int>>pq;
       pq.push({start,0});
       vector<int>res(100000,INT_MAX);
       res[start]=0;
       while(!pq.empty()){
           int node=pq.front().first;
           int step=pq.front().second;
           pq.pop();
           for(int i=0;i<arr.size();i++){
               int x=(node*arr[i])%mod;
               if(res[x]>step+1){
                   res[x]=step+1;
                   if(end==x)return step+1;
                   pq.push({x,step+1});
               }
           }
       }
      
       return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends