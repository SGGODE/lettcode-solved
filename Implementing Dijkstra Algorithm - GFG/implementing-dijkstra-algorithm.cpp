//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int>dijkstra(int V, vector<vector<int>>adj[], int S)
    {
        // Code here
        vector<int>res(V,INT_MAX);
        vector<pair<int,int>>dumpadj[V+1];
        for(int i=0;i<V;i++){
            if(adj[i].empty())continue;
            else{
                for(auto it:adj[i]){
                  // cout<<it[0]<<" "<<it[1]<<endl;
                    dumpadj[i].push_back({it[0],it[1]});
                }
            }
        }
      queue<pair<int,int>>pq;
      set<pair<int,int>>s;
      s.insert({0,S});
        pq.push({0,S});
        res[S]=0;
        while(!s.empty()){
            auto it = *(s.begin());
            int temp=it.second;
            int time=it.first;
            s.erase(it);
            for(auto it:dumpadj[temp]){
                if(res[it.first]>res[temp]+it.second){
                    res[it.first]=res[temp]+it.second;
                    s.insert({it.second,it.first});
                }
            }
        }
        
        return res;
        return {0,9};
       
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends