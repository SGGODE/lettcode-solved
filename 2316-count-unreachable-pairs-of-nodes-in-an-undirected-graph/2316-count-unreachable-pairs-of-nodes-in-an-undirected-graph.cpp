class Solution {
private:
    void dfs(vector<int>adj[],int src,vector<bool>&vis,long long int&cnt){
        if(vis[src])return;
        ++cnt;
        vis[src]=1;
        for(auto it:adj[src]){
            if(!vis[it]){
                dfs(adj,it,vis,cnt);
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,0);
        vector<int>adj[n+1];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
        }
      long long int regions=0;
      long long int cnt=0;
      long long int total=0;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ++regions;
               long long int curr=0;
                dfs(adj,i,vis,curr);
                //cnt+=curr;
                if(regions>1){
                    total+=(cnt*curr);
                }
                cnt+=curr;
                v.push_back({i,curr});
            }
        }
        if(regions>1){
           return total; 
        }
        return 0;
    }
};