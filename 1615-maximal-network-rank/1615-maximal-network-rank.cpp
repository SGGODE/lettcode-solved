class Solution {
private:
    int bfs(vector<int>adj[],vector<bool>&vis,int src){
        vis[src]=1;
        queue<int>pq;
        pq.push(src);
        int cnt = 1;
        while(!pq.empty()){
            int node = pq.front();
            pq.pop();
            for(auto&it:adj[node]){
                if(!vis[it]){
                    ++cnt;vis[it]=1;
                    pq.push(it);
                }
            }
        }
        return cnt;
    }
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // if(roads.empty())return 0;
        // if(roads.size()==1)return 1;
        // if(roads.size()==2)return 2;
        set<pair<int,int>>s;
        vector<int>node(n,0);
       // vector<int>adj[n];
        for(int i=0;i<roads.size();i++){
            // adj[roads[i][0]].push_back(roads[i][1]);
            // adj[roads[i][1]].push_back(roads[i][0]);
            s.insert({roads[i][0],roads[i][1]});
            s.insert({roads[i][1],roads[i][0]});
            node[roads[i][0]]++;
            node[roads[i][1]]++;
        }
        // vector<bool>vis(n,0);
         int network = 0;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         int networksize = bfs(adj,vis,i);
        //         network = max(network,networksize);
        //     }
        // }
        // return network;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum = node[i]+node[j];
                if(s.find({i,j})!=s.end()||s.find({j,i})!=s.end()){
                    sum-=1;
                }
                network=max(network,sum);
            }
        }
        return network;
    }
};