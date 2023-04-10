class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>res(n+1,1e9);
        res[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                if(res[it.first]>dist+it.second){
                    res[it.first]=dist+it.second;
                    pq.push({it.second+dist,it.first});
                }
            }
        }
        res[0]=-1;
        for(int i=1;i<=n;i++){
            if(res[i]==1e9)return -1;
        }
        return *max_element(res.begin(),res.end());
    }
};