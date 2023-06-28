class Solution {
private:
    void dfs(int start,int end,double dist,vector<pair<int,double>>adj[],vector<double>&res,vector<bool>&vis,int org){
        vis[start]=1;
        if(start!=org)res[start]=max(res[start],dist);
       // cout<<start<<" "<<dist<<endl;
        for(auto&it:adj[start]){
            if(!vis[it.first]){
                dfs(it.first,end,dist*it.second,adj,res,vis,org);
            }
        }
        vis[start]=0;
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>&nums, int start, int end) {
        vector<pair<int,double>>adj[n+1];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],nums[i]});
            adj[edges[i][1]].push_back({edges[i][0],nums[i]});
        }
        vector<double>res(n+1,-1e5);
        res[start]=0;
       // vector<bool>vis(n+1,0);
      //  dfs(start,end,1,adj,res,vis,start);
        queue<pair<pair<int,double>,unordered_map<int,int>>>pq;
        unordered_map<int,int>mp;
        mp[start]++;
        pq.push({{start,1},mp});
        while(!pq.empty()){
            int node=pq.front().first.first;
            double dist=pq.front().first.second;
            unordered_map<int,int>mx=pq.front().second;
            pq.pop();
            if(node==end)continue;
            for(auto&it:adj[node]){
                if(mx.count(it.first)==0&&res[it.first]<dist*it.second){
                    res[it.first]=max(res[it.first],dist*it.second);
                    mx[it.first]++;
                    pq.push({{it.first,dist*it.second},mx});
                    mx.erase(it.first);
                }
             }
            }
        return res[end]==-1e5?0:res[end];
    }
};