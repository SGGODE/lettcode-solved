//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   void dfs(vector<int>adj[],vector<bool>&vis,vector<int>&res,int src,int time){
       
       for(auto it:adj[src]){
          
       }
   }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
         vector<int>res(N,INT_MAX);
        vector<pair<int,int>>adj[N+1];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
          // adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>vis(N+1,0);
        queue<int>pq;
        pq.push(0);
        res[0]=0;
        while(!pq.empty()){
            int temp=pq.front();
            pq.pop();
            for(auto it:adj[temp]){
                if(res[it.first]>res[temp]+it.second){
                    res[it.first]=res[temp]+it.second;
                    pq.push(it.first);
                }
            }
        }
          for(int i=0;i<N;i++){
            if(res[i]==INT_MAX)res[i]=-1;
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends