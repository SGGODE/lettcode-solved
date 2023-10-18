class Solution {
public:
    //network delay
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        if(relations.empty())return *max_element(time.begin(),time.end());;
        vector<int>indegree(n,0);
        vector<int>adj[n];
        for(int i=0;i<relations.size();i++){
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
            indegree[relations[i][1]-1]++;
        }
        vector<int>dj(n,0);
        queue<int>pq;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                pq.push(i);
                dj[i]=time[i];
            }
        }
        while(!pq.empty()){
            int node = pq.front();
            //int t = pq.front().second;
            pq.pop();
            for(auto&it:adj[node]){
                --indegree[it];
                if(dj[node]+time[it]>dj[it]){
                    dj[it]=dj[node]+time[it];
                }
                if(indegree[it]==0){
                     pq.push(it);
                }
            }
        }
        return *max_element(dj.begin(),dj.end());
    }
};