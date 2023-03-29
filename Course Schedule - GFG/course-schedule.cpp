//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
      //  map<int,int>income;
      vector<int>income(n,0);
        vector<int>adj[n+1];
        for(int i=0;i<m;i++){
          //  income[pre[i][0]]++;
            adj[pre[i][1]].push_back(pre[i][0]);
           // income[pre[i][1]]=0;
        }
        queue<int>pq;
        for(int i=0;i<n;i++){
           for(auto it:adj[i]){
               income[it]++;
           }
        }
        for(int i=0;i<n;i++){
            if(income[i]==0)pq.push(i);
        }
        vector<int>res;
        //vector<bool>vis(n,0);
        while(!pq.empty()){
            int temp=pq.front();
            pq.pop();
            res.push_back(temp);
          //  vis[temp]=1;
            for(auto it:adj[temp]){
                --income[it];
                if(income[it]==0){
                    pq.push(it);
                   // income.erase(it);
                }
            }
        }
      // for(auto it:res)cout<<it<<" ";
      if(res.size()!=n)return {};
        return res;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
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
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends