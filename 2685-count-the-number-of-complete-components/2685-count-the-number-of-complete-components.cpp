class Solution {
private:
    void dfs(vector<int>adj[],vector<bool>&vis,vector<int>&temp,int src){
        vis[src]=1;
        temp.push_back(src);
        for(auto &it:adj[src]){
            if(!vis[it]){
                dfs(adj,vis,temp,it);
            }
        }
    }
    bool check(vector<int>adj[],vector<int>&temp){
        int n=temp.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                bool flag=0;
                for(auto &it:adj[temp[i]]){
                    if(it==temp[j]){
                        flag=1;break;
                    }
                }
                if(!flag)return 0;
            }
        }
        return 1;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,0);
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>temp;
                dfs(adj,vis,temp,i);
                if(check(adj,temp))++cnt;
            }
        }
        return cnt;
    }
};