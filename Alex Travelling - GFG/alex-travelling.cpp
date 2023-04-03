//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<int>res(n+1,INT_MAX);
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        // for(int i=0;i<n;i++){
        //     for(auto it:adj[i])cout<<it.first<<" "<<it.second<<endl;
        // }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        res[k]=0;
        while(!pq.empty()){
            int cost=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(res[it.first]>res[node]+it.second){
                    res[it.first]=res[node]+it.second;
                    pq.push({res[node]+it.second,it.first});
                }
            }
        }
       // for(auto it:res)cout<<it<<" ";
        //cout<<endl;
        res[0]=-1;
        for(int i=1;i<=n;i++){
            if(res[i]==INT_MAX)return -1;
        }
        return *max_element(res.begin(),res.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends