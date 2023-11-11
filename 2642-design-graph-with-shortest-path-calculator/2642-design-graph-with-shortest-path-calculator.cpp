class Graph {
public:
    vector<pair<int,int>>adj[101];
    Graph(int n, vector<vector<int>>& edges) {
        for(auto&it:edges){
            adj[it[0]].push_back({it[1],it[2]});
           // adj[it[1]].push_back({it[0],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
       // adj[edge[1]].push_back({edge[0],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dist(101,1e9);
        dist[node1]=0;
        queue<int>pq;
        pq.push(node1);
        while(!pq.empty()){
            int node = pq.front();
            pq.pop();
            for(auto&it:adj[node]){
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first]=dist[node]+it.second;
                    pq.push(it.first);
                }
            }
        }
        return dist[node2]!=1e9?dist[node2]:-1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */