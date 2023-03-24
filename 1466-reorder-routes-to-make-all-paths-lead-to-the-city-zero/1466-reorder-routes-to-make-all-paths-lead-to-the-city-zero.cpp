class Solution {
private:
    void check(set<int>outgo[],int start,int target,bool&flag,vector<bool>&vis){
        if(vis[start])return;
        vis[start]=1;
        for(auto it:outgo[start]){
            if(it==target){
                flag=1;
                return;
            }
            check(outgo,it,target,flag,vis);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        map<pair<int,int>,int>mp;
        for(auto it:connections){
            mp[{it[0],it[1]}]++;
        }
        vector<int>adj[n+1];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        queue<int>pq;
        pq.push(0);
        int cnt=0;
        vector<bool>vis(n,0);
        while(!pq.empty()){
            vis[pq.front()]=1;
            for(auto it:adj[pq.front()]){
                if(!vis[it]){
                pq.push(it);
                if(mp.count({pq.front(),it}))++cnt;
                }
            }
            pq.pop();
        }
        return cnt;
    }
};