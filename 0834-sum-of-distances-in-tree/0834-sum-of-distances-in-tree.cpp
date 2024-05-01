// class Solution {
// private:
//     map<pair<int,int>,int>dp;
//     void dfs(vector<int>adj[],vector<bool>&vis,int src,int par,int curr,int&dist){
//         vis[src]=1;
//         dp[{par+1,src+1}]=(dist+curr);
//         dist+=curr;
//         for(auto&it:adj[src]){
//           //  if(dp.count({src+1,it+1})&&!vis[it]){dist+=dp[{src+1,it+1}];continue;}
//             if(!vis[it]){
//                 dfs(adj,vis,it,src,curr+1,dist);
//             }
//         } 
//     }
// public:
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
//         vector<int>adj[n];
//         for(auto&it:edges){
//             adj[it[0]].push_back(it[1]);
//             adj[it[1]].push_back(it[0]);
//         }
//         vector<int>result;
//         for(int i=0;i<n;i++){
//             vector<bool>vis(n,0);
//             int dist = 0;
//             dfs(adj,vis,i,-1,0,dist);
//             vis.clear();
//             result.push_back(dist);
//         }
//         return result;
//     }
// };
class Solution {
	int n;
	vector<list<int>> adjList;
	vector<int> sz, val, ans;

	void dfs1(int node, int par) {

		for (int child : adjList[node]) {
			if (child != par) {
				dfs1(child, node);
				sz[node] += sz[child];
				val[node] += val[child] + sz[child];
			}
		}
		sz[node]++;
	}

	void dfs2(int node, int par, int dpVal) {
		ans[node] = val[node] + dpVal + (n - sz[node]);

		for (int child : adjList[node]) {
			if (child != par)
				dfs2(child, node, ans[node] - val[child] - sz[child]);
		}
	}
    
public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
		n = N;
		adjList.resize(n), sz.resize(n), val.resize(n), ans.resize(n);
		for (vector<int> &v : edges) {
			adjList[v[0]].push_back(v[1]);
			adjList[v[1]].push_back(v[0]);
		}
		dfs1(0, 0);
		dfs2(0, 0, 0);
		return ans;
	}
};