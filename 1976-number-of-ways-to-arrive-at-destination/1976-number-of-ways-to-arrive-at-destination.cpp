class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
//     int mod=1000000000+7;
//       vector<pair<int,int>>adj[n];
//       for(auto it:roads){
//           adj[it[0]].push_back({it[1],it[2]});
//           adj[it[1]].push_back({it[0],it[2]});
//       }
//       priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>pq;
//       pq.push({0,0});
//       vector<long long int>res(n,INT_MAX);
//       vector<long long int>way(n,0);
//       res[0]=0;
//       way[0]=1;
//       vector<bool>vis(n,0);
//       while(!pq.empty()){
//          long long int cost=pq.top().first;
//          long long int node=pq.top().second;
//           pq.pop();
//           vis[node]=1;
//           for(auto it:adj[node]){
//              long long int adjnode=it.first;
//              long long int edgewt=it.second;
//               if(cost+edgewt < res[adjnode]){
//                  res[adjnode]=cost+edgewt;
//                   way[adjnode]=(way[node])%mod;
//                //   temp.push_back(adjnode);
//                   pq.push({cost+edgewt,adjnode});
//                 //  temp.pop_back();
//              }else if(cost+edgewt==res[adjnode]){
//                   way[adjnode]=(way[adjnode]+way[node])%mod;
//               }
//           }
//       }
   
//         return way[n-1]%mod;
            // Creating an adjacency list for the given graph.
         vector<pair<long long, long long>> adj[n];
        for(auto i: roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        vector<long long> dis(n, LONG_MAX);
        vector<long long> ways(n);
        
        dis[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        long long mod = 1e9+ 7;
        
        while(!pq.empty()){
            
            long long nodeWt = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
                
            // if(nodeWt > dis[node]) continue;
            
            for(auto i: adj[node]){
                
                long long child = i.first;
                long long childWt = i.second;
                
                if(childWt + nodeWt < dis[child]){
                    dis[child] = childWt + nodeWt;
                    pq.push({dis[child], child});
                    ways[child] = ways[node];
                }
                else if(childWt + nodeWt == dis[child]){
                    ways[child] = (ways[child] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};