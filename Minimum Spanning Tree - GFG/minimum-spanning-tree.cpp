//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<long long int,long long int>>dump[V+1];
        for(int i=0;i<V;i++){
          for(auto it:adj[i]){
              dump[i].push_back({it[0],it[1]});
              dump[it[0]].push_back({i,it[1]});
          }
        }
        vector<long long int>curr[V+1];
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>pq;
        for(auto it:dump[0]){
            pq.push({it.second,it.first});
        }
        vector<bool>vis(V,0);
       long long int sum=0;
        vis[0]=1;
        while(!pq.empty()){
           long long int temp=pq.top().second;
           long long int xum=pq.top().first;
           if(vis[temp]){
               pq.pop();continue;
           }
            pq.pop();
            vis[temp]=1;
            for(auto it:dump[temp]){
                if(vis[it.first])continue;
                else{
                    pq.push({it.second,it.first});
                }
            }
           sum+=xum;
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends