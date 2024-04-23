class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>top(n,0);
        for(auto&it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            top[it[0]]++;
            top[it[1]]++;
        }
        queue<int>pq;
        for(int i=0;i<n;i++){
            if(top[i]==1)pq.push(i);
        }
        vector<int>result;
        while(!pq.empty()){
            int nodes = pq.size();
            result.clear();
            for(int i=0;i<nodes;i++){
                int node = pq.front();pq.pop();
                for(auto&it:adj[node]){
                    --top[it];
                    if(top[it]==1)pq.push(it);
                }
                result.push_back(node);
            }
        }
        if(n==1)result.push_back(0);
        return result;
    }
};