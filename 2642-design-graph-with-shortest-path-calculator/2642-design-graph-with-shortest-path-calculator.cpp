class Graph {
public:
    vector<pair<int,int>>adj[101];
   // vector<int>res(100,INT_MAX);
    Graph(int n, vector<vector<int>>& edges) {
       // adj.resize(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>res(101,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node1});
        res[node1]=0;
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            for(auto it:adj[node]){
                if(res[it.first]>dist+it.second){
                    res[it.first]=dist+it.second;
                    pq.push({dist+it.second,it.first});
                }
            }
            pq.pop();
        }
        if(res[node2]==INT_MAX)return -1;
        return res[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */