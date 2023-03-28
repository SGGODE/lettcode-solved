//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(vector<int>adj[],int src,vector<bool>&vis,vector<int>&res){
	    if(vis[src])return;
	    vis[src]=1;
	    for(auto it:adj[src]){
	        if(!vis[it])dfs(adj,it,vis,res);
	    }
	    res.push_back(src);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   vector<int>res;
	   // stack<int>s;
	   // vector<bool>vis(V,0);
	   // for(int i=0;i<V;i++){
	   //     if(!vis[i]){
	   //         dfs(adj,i,vis,res);
	   //     }
	   // }
	   // reverse(res.begin(),res.end());
	   // return res;
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
// 	  for(auto it:indegree)cout<<it<<" ";
// 	  cout<<endl;
	   while(!pq.empty()){
	       int x=pq.front();
	       pq.pop();
	    //   cout<<x<<endl;
	       res.push_back(x);
	       for(auto it:adj[x]){
	           --indegree[it];
	           if(indegree[it]==0){
	               pq.push(it);
	           }
	       }
	   }
	   //for(auto it:res)cout<<it<<" ";
	   //cout<<endl;
	   return res;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends