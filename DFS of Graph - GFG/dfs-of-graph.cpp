//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int>&result,vector<bool>&vis,vector<int>adj[],int index){
        if(vis[index])return;
        vis[index]=1;
        //cout<<index<<endl;
        result.push_back(index);
        for(auto it:adj[index]){
            if(!vis[it]){
                dfs(result,vis,adj,it);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int>result;
       vector<bool>vis(V,0);
       for(int i=0;i<V;i++){
           if(!vis[i]){
               dfs(result,vis,adj,i);
           }
       }
       
       return result;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends