class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
    friend class Soluction;
}; 
// int main() {
//     DisjointSet ds(7);
//     ds.unionBySize(1, 2); 
//     ds.unionBySize(2, 3); 
//     ds.unionBySize(4, 5); 
//     ds.unionBySize(6, 7); 
//     ds.unionBySize(5, 6); 
//     // if 3 and 7 same or not 
//     if(ds.findUPar(3) == ds.findUPar(7)) {
//         cout << "Same\n"; 
//     }
//     else cout << "Not same\n"; 

//     ds.unionBySize(3, 7); 

//     if(ds.findUPar(3) == ds.findUPar(7)) {
//         cout << "Same\n"; 
//     }
//     else cout << "Not same\n"; 
// 	return 0;
// }
class Solution {
private:
     void check(int start,vector<int>adj[],vector<bool>&vis){
         if(vis[start])return;
         vis[start]=1;
         for(auto it:adj[start]){
             check(it,adj,vis);
         }
     }
public:
    int makeConnected(int n, vector<vector<int>>& connections) { 
        vector<int>adj[n+1];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        DisjointSet ds(n);
        int extra=0;
        for(int i=0;i<connections.size();i++){
            if(ds.findUPar(connections[i][0])==ds.findUPar(connections[i][1]))++extra;
            ds.unionBySize(connections[i][0],connections[i][1]);
        }
        vector<bool>vis(n,0);
        check(0,adj,vis);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ++cnt;
                check(i,adj,vis);
            }
        }
        if(cnt<=extra)return cnt;
        return -1;
    }
};