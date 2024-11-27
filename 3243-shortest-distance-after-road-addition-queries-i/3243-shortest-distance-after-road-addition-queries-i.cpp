class Solution {
private:
    int shortestPath(vector<int>adj[],int n){
        vector<int>dist(n , 1e9);
        dist[0] = 0;
        queue<int>pq;
        pq.push(0);
        while(!pq.empty()){
            int node = pq.front();
            pq.pop();
            for(auto & it : adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    pq.push(it);
                }
            }
        }
        return dist[n-1];
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
         vector<int>adj[n];
         vector<int>result;
         for(int i = 1; i < n; i++){
             adj[i-1].push_back(i);
         }
         for(auto & it : queries){
             adj[it[0]].push_back(it[1]);
             result.push_back(shortestPath(adj,n));
         }
        return result;
    }
};