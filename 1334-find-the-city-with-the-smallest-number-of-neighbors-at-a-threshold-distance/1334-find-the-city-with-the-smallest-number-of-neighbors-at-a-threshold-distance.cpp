class Solution {
private:
    int Dijkstra(int n,int src,int dist,vector<pair<int,int>>adj[]){
        vector<int>res(n,1e9);
        res[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            for(auto&it:adj[node]){
                if(res[it.first]>cost+it.second&&cost+it.second<=dist){
                    res[it.first]=it.second+cost;
                    pq.push({it.second+cost,it.first});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i!=src&&res[i]<=dist)++cnt;
        }
        return cnt;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
       // for(int i=0;i<)
        int node = -1;
        int numberofnodes = INT_MAX;
        for(int i=0;i<n;i++){
            int peers = Dijkstra(n,i,distanceThreshold,adj);
            if(peers <= numberofnodes){
                numberofnodes = peers;
                node = i;
            }
           // cout<<peers<<" "<<i<<endl;
        }
        return node;
    }
};