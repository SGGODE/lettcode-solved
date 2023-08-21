class DisjointSet{
  vector<int>rank,size,parent;
  public:
    DisjointSet(int n){
		rank.resize(n+1,0);
		parent.resize(n+1);
		size.resize(n+1);
		for(int i=0;i<=n;i++){
			size[i]=1;
			parent[i]=i;
		}
	}
	int findpar(int n){
		if(n==parent[n])return n;
		return parent[n]=findpar(parent[n]);
	}
	void unionbyrank(int u,int v){
		int par_u = findpar(u);
		int par_v = findpar(v);
		if(par_u==par_v)return;
        if(rank[par_u]<rank[par_v]){
			parent[par_u]=par_v;
		}else if(rank[par_u]>rank[par_v]){
			parent[par_v]=par_u;
		}else{
			rank[par_u]++;
			parent[par_u]=par_v;
		}
	}
	void unionbysize(int u,int v){
		int par_u = findpar(u);
		int par_v = findpar(v);
		if(par_u==par_v)return;
        if(size[par_u]<size[par_v]){
			parent[par_u]=par_v;
			size[par_v]+=size[par_u];
		}else{
			parent[par_u]=par_v;
			size[par_u]+=size[par_v];
		}
	}
};

class Solution {
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
        DisjointSet ds(n);
        int cnt=0;
        vector<bool>vis(n,0);
        for(int i=0;i<connections.size();i++){
            if(ds.findpar(connections[i][0])!=ds.findpar(connections[i][1])){
                ds.unionbyrank(connections[i][0],connections[i][1]);
               // vis[connections[i][0]]=1;
               // vis[connections[i][1]]=1;
            }else{
                ++cnt;
            }
        }
        vector<int>adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
       // vector<bool>vis(n,0);
        int req=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ++req;
                dfs(adj,vis,i);
            }
        }
        return cnt>=req-1?req-1:-1;
    }
};