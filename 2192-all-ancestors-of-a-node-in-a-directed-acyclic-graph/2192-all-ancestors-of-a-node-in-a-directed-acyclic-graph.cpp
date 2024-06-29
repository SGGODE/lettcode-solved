class Solution {

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n);
        vector<int>adj[n];
        for(auto&it:edges){
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        queue<int>pq;
        vector<set<int>>result(n);
        for(int i = 0; i < n ; i++){
            if(indegree[i]==0){
                pq.push(i);
            }
        }
        while(!pq.empty()){
            int size = pq.size();
            for(int i = 0 ; i < size ; i++){
                int node = pq.front();
                pq.pop();
                for(auto &it : adj[node]){
                    --indegree[it];
                    set<int>resit = result[it],resnode = result[node];
                    resit.insert(resnode.begin(),resnode.end());
                    result[it]=resit;
                    result[it].insert(node);
                    if(indegree[it]==0)pq.push(it);
                }
            }
        }
        vector<vector<int>>finalAncestors(n);
        for(int i = 0; i < n ;i++){
            set<int> s = result[i];
            vector<int> vec(s.begin(),s.end());
            finalAncestors[i] = vec;
            // for(auto&it:s)cout<<it<<" ";
            // cout<<endl;
        }
        return finalAncestors;
    }
};