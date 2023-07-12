class Solution {
private:
    void dfs(vector<int>&dp,vector<int>adj[],vector<bool>&vis,int node,unordered_map<int,int>&mp,bool&flag){
        vis[node]=1;
        //ut<<"call "<<node<<endl;
        if(mp.count(node)){
            vis[node]=0;
            return;
        }
        if(flag){
           //out<<"last "<<node<<endl;
            dp[node]=0;
            vis[node]=0;
            return;
        }
        for(auto&it:adj[node]){
            if(flag){
                dp[node]=0;
                return;
            }
            if(!vis[it]){
                dfs(dp,adj,vis,it,mp,flag);
            }
            if(vis[it]&&mp.find(it)==mp.end()){
               //out<<"parent and node "<<it<<" "<<node<<endl;
                dp[it]=0;dp[node]=0;
                flag=1;
            }
        }
        if(flag)dp[node]=0;
        vis[node]=0;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        // vector<int>outcomes(n,0);
        // for(int i=0;i<n;i++){
        //     outcomes[i]+=graph[i].size();
        // }
        // vector<int>adj[n+1];
        // for(int i=0;i<n;i++){
        //     for(auto&it:graph[i]){
        //         adj[i].push_back(it);
        //     }
        // }
        // vector<int>terminal; vector<int>dp(n+1,-1);
        // unordered_map<int,int>mp;vector<bool>vis(n+1,0);
        // for(int i=0;i<n;i++){
        //     if(outcomes[i]==0){
        //         terminal.push_back(i);
        //         dp[i]=1;
        //        // vis[i]=1;
        //         mp[i]++;
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(outcomes[i]!=0){
        //         bool flag=0;
        //         if(dp[i]==0)continue;
        //        if(dp[i]==-1){
        //         // cout<<"I am calling "<<i<<endl;
        //            dfs(dp,adj,vis,i,mp,flag);
        //            if(!flag){
        //             dp[i]=1;
        //             terminal.push_back(i);
        //             mp[i]++;
        //         }else dp[i]=0;
        //            continue;
        //        }
        //        if(dp[i]){
        //            terminal.push_back(i);
        //            //continue;
        //        }
        //     }
        // }
        // for(auto&it:dp)cout<<it<<" ";
        // cout<<endl;
        // sort(terminal.begin(),terminal.end());
        // return terminal;
        vector<int>income(n+1,0);vector<int>adj[n+1];
        for(int i=0;i<n;i++){
             for(auto&it:graph[i]){
                adj[it].push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            for(auto&it:adj[i]){
                income[it]++;
            }
        }
        queue<int>pq;
        for(int i=0;i<n;i++){
            if(income[i]==0)pq.push(i);
        }
        set<int>s;
        while(!pq.empty()){
            int node=pq.front();
            pq.pop();
            s.insert(node);
            for(auto&it:adj[node]){
                --income[it];
                if(income[it]==0)pq.push(it);
            }
        }
        vector<int>res(s.begin(),s.end());
        return res;
    }
};