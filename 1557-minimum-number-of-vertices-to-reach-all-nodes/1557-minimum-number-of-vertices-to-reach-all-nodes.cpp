class Solution {
private:
    void dfs(vector<int>adj[],vector<bool>&vis,int src){
        vis[src]=1;
        for(auto &it:adj[src]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>res;
        vector<int>adj[n];
        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        // int mincnt=INT_MAX;
        // for(int i=0;i<n;i++){
        //         vector<bool>vis(n,0);
        //         vector<int>temp;
        //         int cnt=1;dfs(adj,vis,i);
        //         temp.push_back(i);
        //         for(int j=0;j<n;j++){
        //                 if(!vis[j]){
        //                     ++cnt;
        //                     temp.push_back(j);
        //                     dfs(adj,vis,j);
        //                 }
        //         }
        //     if(cnt<mincnt||res.size()>temp.size()){
        //        sort(temp.begin(),temp.end());
        //         res=temp;
        //         mincnt=cnt;
        //     }
        // }
        for(int i=0;i<n;i++){
            if(indegree[i]==0)res.push_back(i);
        }
        return res;
    }
};