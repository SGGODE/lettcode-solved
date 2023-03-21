//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
  bool check(vector<bool>&vis,vector<int> adj[],int src){
       queue<pair<int,int>>pq;
       pq.push({src,-1});
      // vector<bool>vis(V,0);
      // vis[0]=1;
       while(!pq.empty()){
           int curr=pq.front().first;
           vis[curr]=1;
           int parent=pq.front().second;
           for(auto it:adj[curr]){
               if(it==parent)continue;
               if(vis[it])return 1;
               else{
                   vis[it]=1;
                   pq.push({it,curr});
               }
           }
           pq.pop();
       }
       return 0;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V,0);
       for(int i=0;i<V;i++){
           if(!vis[i]&&check(vis,adj,i)){
               return 1;
           }
       }
       return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends