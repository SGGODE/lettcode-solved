// class Solution {
// private:
//    long long int answer=0;
// //     void dfs(vector<int>adj[],int index,int cur_vist,int seats,curr_count,vector<bool>&vis){
// //         if(){
            
// //         }
// //         cur_vist[index]=1;
// //         for(auto it:adj[index]){
// //             if(seats>0){
// //                 --seats;
// //                 cur_vist[it]=1;
// //                 vis[index]=1;
// //                 dfs(adj,it,)
// //             }
// //         }
// //     }
//     int dfs(int node, int parent, vector<int>adj[], int seats) {
//         int person = 1;
//         for (int nbr : adj[node]) {
//             if (nbr == parent) {
//                 continue;
//             }

//             person += dfs(nbr, node, adj, seats);
//         }

//         if (node != 0) {
//             answer += ceil((double)person/seats);
//         }

//         return person;
//     }
// public:
//     long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
//         int n=roads.size();
//         vector<int>adj[n];
//         for(int i=0;i<n;i++){
//             adj[roads[i][0]].push_back(roads[i][1]);
//             adj[roads[i][1]].push_back(roads[i][0]);
//         }
//        //  vector<bool>vis(n,0);
//        // long long int result=0;
//        //  for(int i=1;i<n;i++){
//        //      if(!vis[i]){
//        //        long long int cnt=0;
//        //          vector<bool>cur_vist;
//        //          int curr_count=1;
//        //          dfs(adj,i,cur_vist,seats,curr_count.vis);
//        //          result+=cnt;
//        //      }
//        //  }
//        //  return result;
//         dfs(0,-1,adj,seats);
//         return answer;
//     }
// };
class Solution {
    long long answer = 0;
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> g(n);
        for (auto road: roads) {
            int a = road[0], b = road[1];
            // a -> b & b -> a
            g[a].push_back(b);
            g[b].push_back(a);
        }

        // u - v

        dfs(0, -1, g, seats);
        return answer;
    }

    int dfs(int node, int parent, vector<vector<int>>& g, int seats) {
        int person = 1;
        for (int nbr : g[node]) {
            if (nbr == parent) {
                continue;
            }

            person += dfs(nbr, node, g, seats);
        }

        if (node != 0) {
            answer += ceil((double)person/seats);
        }

        return person;
    }
};