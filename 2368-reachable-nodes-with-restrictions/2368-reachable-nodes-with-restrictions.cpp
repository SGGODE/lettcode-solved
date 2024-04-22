class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool>vis(n,0);
        vector<int>adj[n];
        for(auto&it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        set<int>st;
        for(auto&it:restricted)st.insert(it);
        queue<int>pq;
        pq.push(0);
        vis[0]=1;
        while(!pq.empty()){
            int node = pq.front();
            pq.pop();
            for(auto&it:adj[node]){
                if(!vis[it]&&!st.count(it)){
                    vis[it]=1;pq.push(it);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(vis[i])++cnt;
         //   else cout<<i<<" ";
        }
        return cnt;
    }
};