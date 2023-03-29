class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n+1];
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int>income(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i])income[it]++;
        }
        queue<int>pq;
        for(int i=0;i<n;i++){
            if(income[i]==0)pq.push(i);
        }
        vector<int>res;
        while(!pq.empty()){
            int temp=pq.front();
            pq.pop();
            res.push_back(temp);
            for(auto it:adj[temp]){
                --income[it];
                if(income[it]==0){
                    pq.push(it);
                }
            }
        }
        return res.size()==n;
    }
};