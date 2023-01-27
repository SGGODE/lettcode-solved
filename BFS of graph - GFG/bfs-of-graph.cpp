//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>s;
        unordered_map<int,int>mp;
        queue<int>q;
        q.push(0);
        s.push_back(0);
        mp[0]++;
        while(!q.empty()){
            for(auto it:adj[q.front()]){
                if(mp.find(it)==mp.end()){
                 s.push_back(it);
                 mp[it]++;
                 q.push(it);
                }
            }
            q.pop();
        }
        //vector<int>v(s.begin(),s.end());
        return s;
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