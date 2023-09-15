class Disjointset{
    vector<int>rank,parent;
    public:
    Disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findpar(int par){
        if(par==parent[par])return par;
        return parent[par]=findpar(parent[par]);
    }
    void unionbyrank(int u,int v){
        int par_u=findpar(u);
        int par_v=findpar(v);
        if(par_u==par_v)return;
        if(rank[par_u]>rank[par_v]){
            parent[par_v]=par_u;
        }else if(rank[par_v]>rank[par_u]){
            parent[par_u]=par_v;
        }else{
            parent[par_u]=par_v;
            rank[par_v]++;
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                pq.push({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),{i,j}});
            }
        }
        Disjointset ds(n);
        int sum = 0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int node1 = pq.top().second.first;
            int node2 = pq.top().second.second;
            pq.pop();
            if(ds.findpar(node1)!=ds.findpar(node2)){
                ds.unionbyrank(node1,node2);
                sum+=cost;
            }
        }
        return sum;
    }
};