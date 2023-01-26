// class Solution {
// private:
//     int min_possible=INT_MAX;
//     void dfs(int src,int dst,int k,vector<pair<int,int>>adj[],int cnt,int total,vector<bool>&vis){
//          if(vis[src])return;
//          vis[src]=1;
//         if(k==0){
//            for(auto it:adj[src]){
//                 if(it.first==dst){
//                     total+=it.second;
//                     min_possible=min(min_possible,total);
//                 }
//             }
//           return;
//         }
//         for(auto it:adj[src]){
//             if(it.first==dst){
//                     total+=it.second;
//                     min_possible=min(min_possible,total);
//                   // return;
//                    dfs(it.first,dst,k-1,adj,cnt,total,vis);
//             }else dfs(it.first,dst,k-1,adj,cnt,total+it.second,vis);
//         }
//     }
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//       //  if(src==dst)return 0;
//         vector<pair<int,int>>adj[n];
//         for(int i=0;i<flights.size();i++){
//             adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
//         }
//         // for(auto it:adj){
//         //     for(auto vt:it)cout<<vt.first<<" "<<vt.second<<" ";
//         //     cout<<endl;
//         // }
//         if(k==0){
//             bool flag=1;
//             for(auto it:adj[src]){
//                 if(it.first==dst){
//                     flag=0;
//                     return it.second;
//                 }
//             }
//             if(flag)return -1;
//         }
//         int cnt=k; vector<bool>vis(n,0);
//         // for(auto it:adj[src]){
//         //  
//         //   vis[src]=1;
//         //   dfs(it.first,dst,k-1,adj,cnt,it.second,vis);
//         // }
//         dfs(src,dst,k,adj,cnt,0,vis);
//         if(min_possible==INT_MAX)return -1;
//         return min_possible;   
//     }
// };
class Solution {
    const int inf = 1e8;
    int dp[101][101];

public:
    int dfs(int node, int k, int dest, vector<vector<int>> &cost, vector<int> adj[])
    {
        if (k < 0)
            return inf;

        if (node == dest)
            return 0;

        if (dp[node][k] != -1)
            return dp[node][k];

        int ans = inf;
        for (auto i : adj[node])
            ans = min(ans, cost[node][i] + dfs(i, k - 1, dest, cost, adj));

        return dp[node][k] = ans;
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        memset(dp, -1, sizeof dp);

        vector<vector<int>> cost(n, vector<int>(n));
        vector<int> adj[n];
        for (auto e : flights)
        {
            adj[e[0]].push_back(e[1]);
            cost[e[0]][e[1]] = e[2];
        }

        int ans = dfs(src, k + 1, dst, cost, adj);
        return ans == inf ? -1 : ans;
    }
};