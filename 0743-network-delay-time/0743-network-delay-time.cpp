class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>res(n+1,1e9);
        queue<int>pq;
        pq.push(k);
        res[k]=0;
        while(!pq.empty()){
            int node=pq.front();
            pq.pop();
            for(auto&it:adj[node]){
                if(res[node]+it.second<res[it.first]){
                    res[it.first]=res[node]+it.second;
                    pq.push(it.first);
                }
            }
        }
        int time = *max_element(res.begin()+1,res.end());
        return time==1e9?-1:time;
    }
};