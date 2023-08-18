class Solution {
public:
    long long int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long int>res(n,LONG_MAX);
        vector<long long int>ways(n,0);
        ways[0]=1;
        res[0]=0;
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long int node=pq.top().second;
            long long int dist=pq.top().first;
            pq.pop();
            for(auto&it:adj[node]){
                if(res[it.first]>dist+it.second){
                    res[it.first]=dist+it.second;
                    ways[it.first]=ways[node];
                    pq.push({dist+it.second,it.first});
                }else if(res[it.first]==dist+it.second){
                    ways[it.first]=(ways[it.first]+ways[node])%mod;
                }
            }
        }
        //cout<<res[n-1]<<endl;
        return ways[n-1];
    }
};