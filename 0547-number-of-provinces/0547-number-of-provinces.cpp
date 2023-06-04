class Solution {
private:
    void bfs(vector<int>adj[],vector<bool>&vis,int index){
        queue<int>pq;
        pq.push(index);
        while(!pq.empty()){
            int node=pq.front();
            pq.pop();
            vis[node]=1;
            for(auto &it:adj[node]){
                if(!vis[it])pq.push(it);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(auto &it:adj[i])cout<<it<<" ";
        //     cout<<endl;
        // }
        vector<bool>vis(n+1,0);
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                ++cnt;
                bfs(adj,vis,i);
            }
        }
        return cnt;
    }
};