// class Disjointset{
//   vector<int>parent,rank;
//    public:
//     Disjointset(int n){
//         parent.resize(n+1);
//         rank.resize(n+1,0);
//         for(int i=0;i<=n;i++){
//             parent[i]=i;
//         }
//     }
//     int par(int root){
//         if(root==parent[root])return root;
//         return parent[root]=par(parent[root]);
//     }
//     void unionrank(int u,int v){
//         int pu=par(u);
//         int pv=par(v);
//         if(pu==pv)return;
//         else if(rank[pu]>rank[pv]){
//             parent[pv]=pu;
//         }
//         else if(rank[pv]>rank[pu]){
//             parent[pu]=pv;
//         }else{
//             parent[pu]=pv;
//             rank[pv]++;
//         }
//     }
// };
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

    int par(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = par(parent[node]); 
    }

    void unionrank(int u, int v) {
        int ulp_u = par(u); 
        int ulp_v = par(v); 
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

    // void unionBySize(int u, int v) {
    //     int ulp_u = findUPar(u); 
    //     int ulp_v = findUPar(v); 
    //     if(ulp_u == ulp_v) return; 
    //     if(size[ulp_u] < size[ulp_v]) {
    //         parent[ulp_u] = ulp_v; 
    //         size[ulp_v] += size[ulp_u]; 
    //     }
    //     else {
    //         parent[ulp_v] = ulp_u;
    //         size[ulp_u] += size[ulp_v]; 
    //     }
    // }
    friend class Soluction;
};
class Solution {
private:
     void dfs(vector<int>adj[],vector<bool>&vis,int src){
         vis[src]=1;
         for(auto it:adj[src]){
             if(!vis[it]){
                 dfs(adj,vis,it);
             }
         }
     }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cnt=0;
        DisjointSet ds(n);
        for(int i=0;i<connections.size();i++){
            if(ds.par(connections[i][0])==ds.par(connections[i][1])){
                ++cnt;
            }else ds.unionrank(connections[i][0],connections[i][1]);
        }
        vector<int>adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool>vis(n,0);
        int curr=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ++curr;
                dfs(adj,vis,i);
            }
        }
        cout<<curr<<endl;
        cout<<cnt<<endl;
        if((curr-1)<=cnt)return curr-1;
        return -1;
    }
};