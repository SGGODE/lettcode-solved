//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool dfs(vector<int>adj[],vector<bool>&vis,vector<bool>&pathvis,int src){
       // if(vis[src])return;
        vis[src]=1;
        pathvis[src]=1;
        for(auto it:adj[src]){
            if(!vis[it]){
                if(dfs(adj,vis,pathvis,it)==1){
                    return 1;
                }
            }else if(pathvis[it])return 1;
        }
       // if(pathvis[src])return 1;
        pathvis[src]=0;
        return 0;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
       vector<bool>vis(V,0);
       vector<bool>pathvis(V,0);
       vector<int>indegree(V,0);
      for(int i=0;i<V;i++){
         for(auto it:adj[i]){
             indegree[it]++;
         }
      }
      queue<int>pq;
      for(int i=0;i<V;i++){
          if(indegree[i]==0){
              pq.push(i);
          }
      }
    //   for(auto it:indegree)cout<<it<<" ";
    //   cout<<endl;
      vector<int>res;
      while(!pq.empty()){
          int x=pq.front();
          pq.pop();
          res.push_back(x);
          for(auto it:adj[x]){
              --indegree[it];
              if(indegree[it]==0)pq.push(it);
          }
      }
      
       return res.size()!=V;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends