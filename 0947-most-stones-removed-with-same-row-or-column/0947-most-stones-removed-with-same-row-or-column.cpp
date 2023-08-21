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
    int sizeofele(int i){
        return size[i];
    }
};
class Solution {
private:
    void dfs(vector<int>adj[],vector<int>&vis,vector<bool>&mark,int src){
        mark[src]=1;
        for(auto&it:adj[src]){
            if(!mark[it]){
                dfs(adj,vis,mark,it);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
       int n=0,m=0;
       for(auto&it:stones){
           n=max(n,it[0]);m=max(m,it[1]);
       }
       DisjointSet ds(n+m+1);
       set<int>s;
       for(int i=0;i<stones.size();i++){
           if(ds.findpar(stones[i][0])!=ds.findpar(stones[i][1]+n+1)){
               ds.unionbyrank(stones[i][0],stones[i][1]+n+1);
               s.insert(stones[i][0]);s.insert(stones[i][1]+n+1);
           }
       }
       int cnt=0;
       for(auto&it:s){
           if(ds.findpar(it)==it)++cnt;
       }
      return stones.size()-cnt;
    }
};