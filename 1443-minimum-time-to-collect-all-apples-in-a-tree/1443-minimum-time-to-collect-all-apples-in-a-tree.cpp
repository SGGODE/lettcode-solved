class Solution {
private:
    int dfs(vector<int>adj[],int index,int sum,vector<bool>& hasApple,vector<bool>&vis){
        if(vis[index])return 0;
        vis[index]=1;
        int cost=0;
        for(auto it:adj[index]){
            // if(hasApple[it]==1&&!vis[it]){
            //     ++sum;
            // }
            // if(!vis[it])
            cost+= dfs(adj,it,2,hasApple,vis);
        }
        if(hasApple[index]==0&&cost==0)return 0;
        return sum+cost;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       vector<int>adj[n];
       for(int i=0;i<edges.size();i++){
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);
       }
       int sum=0;
       vector<bool>vis(n,0);
      return dfs(adj,0,sum,hasApple,vis);
       return 2*sum;
    }
};
