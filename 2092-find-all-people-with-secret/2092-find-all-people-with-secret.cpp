class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
       vector<pair<int,int>>adj[n+1];
       for(auto&it:meetings){
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]});
       }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        map<int,int>mp;
        pq.push({0,0});
        pq.push({0,firstPerson});
        while(!pq.empty()){
            int node = pq.top().second;
            int t = pq.top().first;
            pq.pop();
            if(mp.count(node))continue;
            mp[node]++;
            for(auto&it:adj[node]){
                if(it.second>=t){
                    pq.push({it.second,it.first});
                }
            }
        }
        vector<int>result;
        for(auto&it:mp){
            result.push_back(it.first);
        }
        return result;
    }
};