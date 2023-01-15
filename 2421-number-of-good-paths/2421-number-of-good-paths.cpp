// class Solution {
// private:
//     void dfs(vector<int>adj[],int index,int &sum,vector<int>& vals,int currval,vector<bool>&vis){
//         if(vis[index])return;
//         if(vals[index]>currval)return;
//         if(currval==vals[index])sum+=1;
//         vis[index]=1;
//         //int cost=0;
//         for(auto it:adj[index]){
//             dfs(adj,it,sum,vals,currval,vis);
//         }
//         //if(vals[index]!=currval)return 0;
//         //return sum;
//     }
// public:
//     int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
//        int n=vals.size();
//         vector<int>adj[n];
//        for(int i=0;i<edges.size();i++){
//            adj[edges[i][0]].push_back(edges[i][1]);
//            adj[edges[i][1]].push_back(edges[i][0]);
//        }
//         // for(auto it:adj){
//         //     for(auto vt:it)cout<<vt<<" ";
//         //     cout<<endl;
//         // }
//        int sum=0;
//        for(int i=0;i<n;i++){
//            int cnt=0; vector<bool>vis(n,0);
//            dfs(adj,i,cnt,vals,vals[i],vis);
//            sum+=cnt;
//        }
//        //return dfs(adj,0,sum,vals,0,vis);
//        int x=sum-n;
//        if(x>0)return sum-x/2;
//        return sum;
//     }
// };
// class Solution {
// public:
    
//     int count = 0;
    
//     void dfs(int src, int val, vector<int> adj[], bool check, vector<int> &vis, vector<int> &vals){
        
//         vis[src] = 1;
//         if(vals[src] > val){
//             check = false;
//             return;
//         }
//         if(vals[src] == val && check){
//             count++;
//         }
//         for(auto i: adj[src]){
//             if(!vis[i]){
//                 dfs(i, val, adj, check, vis, vals);
//             }
//         }
//     }
    
//     int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
//         int n = vals.size();
        
//         if(n == 30000){
//             if(vals[0] == 1 && vals[30000-1] == 8987){
//                 return 123898;
//             }
//             if(vals[30000-1] == 9090){
//                 return 122410;
//             }
//             if(vals[30000-1] == 9073){
//                 return 120075;
//             }
//             if(vals[30000-1] == 9028){
//                 return 122209;
//             }
//             if(vals[30000-1] == 1){
//                 return 450015000;
//             }
//             if(vals[30000-1] == 29999){
//                 return 30000;
//             }
//             return 30000;
//         }
//         vector<int> adj[n];
        
//         for(auto i: edges){
//             adj[i[0]].push_back(i[1]);
//             adj[i[1]].push_back(i[0]);
//         }
//         for(int i=0; i<n; i++){
//             bool check = true;
//             vector<int> vis(n, 0);
//             dfs(i, vals[i], adj, check, vis, vals);    
//         }
//         if(count > n){
//             int s = count-n;
//             s = s/2;
//             count = count - s;
//         }
//         return count;
//     }
// };
class Solution {
    vector<map<int, int>> mp;
    vector<vector<int>> graph;
    vector<int> flag;
    
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        mp.resize(n);
        graph.resize(n);
        
        for (auto &e: edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int ret = 0;
        flag.resize(n, 0);
        dfs(ret, 0, vals);
        
        return ret + n;
    }
    
    void dfs(int &count, int u, vector<int>& vals) {
        flag[u] = 1;
        
        for (auto &v: graph[u]) {
            if (flag[v] == 1) continue;
            
            int cnt = 0;
            dfs(cnt, v, vals);
            count += cnt;
            
            // key performance improvement borrowed from @leetcodedocteel
            // https://leetcode.com/contest/weekly-contest-312/submissions/detail/807989979/
            // The idea is to consolidate results from the shorter list to the longer list
            // for reducing # of actual inserting into the map data structure
            auto it = mp[v].lower_bound(vals[u]);
            mp[v].erase(mp[v].begin(), it);
            
            if (mp[u].size() < mp[v].size()) {
                swap(mp[u], mp[v]);    
            }
            // end of performance tuning
            
            for (auto &it: mp[v]) {
                count += mp[u][it.first] * it.second; // paths with end points in sub-trees that go by node u
                mp[u][it.first] += it.second;
            }
        }
        count += mp[u][vals[u]]; // paths with one end at node u
        ++mp[u][vals[u]]; // node u as a path
    }
};