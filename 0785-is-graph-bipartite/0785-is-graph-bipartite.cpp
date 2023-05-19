class Solution {
private:
    bool flag=0;
    void dfs(vector<int>adj[],vector<bool>&vis,vector<int>&color,int src){
        vis[src]=1;
        for(auto &it:adj[src]){
            if(!vis[it]){
              if(color[src]==1)color[it]=0;
              else color[it]=1;
              dfs(adj,vis,color,it);
            }else{
                if(vis[it]&&color[src]==color[it])flag=1;
            }
        }
       // return 0;
    }
public:
    bool isBipartite(vector<vector<int>>&edges) {
        int n=edges.size();
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            for(auto &it:edges[i]){
            adj[i].push_back(it);
            adj[it].push_back(i);
            }
        }
        vector<bool>vis(n,0);
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                color[i]=1;
                dfs(adj,vis,color,i);
            }
        }
        return !flag;
    }
};