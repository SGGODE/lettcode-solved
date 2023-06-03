class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<n;i++){
            if(headID==i)continue;
            adj[i].push_back({manager[i],informTime[manager[i]]});
            adj[manager[i]].push_back({i,informTime[manager[i]]});
        }
        vector<int>res(n,1e9);
        res[headID]=0;
        queue<pair<int,int>>pq;
        pq.push({headID,0});
        while(!pq.empty()){
            int node=pq.front().first;
            int dist=pq.front().second;
            pq.pop();
            for(auto &it:adj[node]){
                if(res[it.first]>res[node]+it.second){
                    res[it.first]=res[node]+it.second;
                    pq.push({it.first,res[node]+it.second});
                }
            }
        }
        return *max_element(res.begin(),res.end());
    }
};