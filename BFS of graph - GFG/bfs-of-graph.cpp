//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
  void bfs(vector<int>&res,vector<bool>&vis,int start,vector<int>adj[]){
      queue<int>pq;
      pq.push(start);
      vis[start]=1;
      while(!pq.empty()){
          int node=pq.front();
          pq.pop();
          res.push_back(node);
          for(auto&it:adj[node]){
              if(!vis[it]){
                  vis[it]=1;
                  pq.push({it});
              }
          }
      }
  }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>res;
        vector<bool>vis(V,0);
        bfs(res,vis,0,adj);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends