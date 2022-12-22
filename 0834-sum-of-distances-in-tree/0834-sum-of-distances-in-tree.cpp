// My TLE one But best one \U0001f914\U0001f601\U0001f44d
// class Solution {
// private:
//     void dfs(vector<int>adj[],vector<bool>&vis,int var,int &sum,int cnt){
//         if(adj[var].empty())return;
//         vis[var]=1;
//         for(auto it:adj[var]){
//             if(!vis[it]){
//              sum+=cnt;
//              dfs(adj,vis,it,sum,cnt+1);
//             }
//         }
//     }
// public:
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
//         vector<int>adj[n];
//         for(int i=0;i<edges.size();i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
//         // for(auto it:adj){
//         //     for(auto vt:it)cout<<vt<<" ";
//         //     cout<<endl;
//         // }
//         vector<int>res(n,0);
//         for(int i=0;i<n;i++){
//             int sum=0;vector<bool>vis(n,0);
//             dfs(adj,vis,i,sum,1);
//             res[i]=sum;
//         }
//         // for(auto it:res)cout<<it<<" ";
//         // cout<<endl;
//         return res;
//     }
// };
class Solution{
    private:
    vector<map<int, pair<int, int>>> graph;

    int dfs(int i, int j){
        if(j!=-1 && graph[j][i].first != -1)
            return graph[j][i].first;

        int sum = 0, count = 0;
        for(auto p : graph[i]){
            if(p.first != j){
                sum += dfs(p.first, i);
                int x = graph[i][p.first].second + 1;

                sum += x;
                count += x;
            }
        }

        if(j != -1){
            graph[j][i].first = sum;
            graph[j][i].second = count;
        }
        return sum;
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n);
        graph = vector<map<int, pair<int, int>>>(n);

        for(auto ed : edges){
            graph[ed[0]][ed[1]] = {-1,0};
            graph[ed[1]][ed[0]] = {-1,0};
        }

        for(int i = 0; i<n; i++)
            ans[i] = dfs(i, -1);

        return ans;
    }
};