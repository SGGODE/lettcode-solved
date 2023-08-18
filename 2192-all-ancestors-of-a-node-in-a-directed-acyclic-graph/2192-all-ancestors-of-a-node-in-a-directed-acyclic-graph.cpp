class Solution {
private:
    void dfs(vector<int>adj[],vector<bool>&vis,set<int>&s,int src){
        //s.insert(src);
        vis[src]=1;
        for(auto&it:adj[src]){
            if(!vis[it]){
                s.insert(it);
                dfs(adj,vis,s,it);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>res;
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!adj[i].empty()){
                set<int>s;
                vector<bool>vis(n,0);
                dfs(adj,vis,s,i);
                vector<int>temp(s.begin(),s.end());
                res.push_back(temp);
            }else{
                res.push_back({});
            }
        }
        return res;
    }
};