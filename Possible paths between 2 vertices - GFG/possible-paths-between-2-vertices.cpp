//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        // for(int i=0;i<V;i++){
        //     for(auto it:adj[i])cout<<it<<" ";
        // }
        set<vector<int>>res;
        queue<vector<int>>pq;
        pq.push({source});
        while(!pq.empty()){
            vector<int>temp=pq.front();
            pq.pop();
            int node=temp.back();
            if(node==destination){
                res.insert(temp);
            }
            for(auto it:adj[node]){
                temp.push_back(it);
                pq.push(temp);
                temp.pop_back();
            }
        }
        return res.size();
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
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends