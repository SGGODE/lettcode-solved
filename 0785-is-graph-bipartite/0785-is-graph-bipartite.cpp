class Solution {
private:
    void dfs(vector<int>adj[],vector<bool>&vis,vector<int>&color,int src,bool&flag){
        if(vis[src])return;
        vis[src]=1;
        for(auto it:adj[src]){
            int parentcolor=color[src];
            if(vis[it]&&parentcolor==color[it]){
                flag=1;
            }
            if(parentcolor==1)color[it]=0;
            else color[it]=1;
            dfs(adj,vis,color,it,flag);
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>vis(n,0);
        vector<int>color(n,-1);
        vector<int>adj[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                 adj[graph[i][j]].push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bool flag=0;
                color[0]=0;
                dfs(adj,vis,color,i,flag);
                if(flag)return 0;
            }
        }
        return 1;
    }
};