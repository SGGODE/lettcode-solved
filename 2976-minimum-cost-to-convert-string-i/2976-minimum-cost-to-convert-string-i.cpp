class Solution {
private:
    void floydWarshall(vector<vector<long long int>>&dist) {
         int V = dist.size();
         int mod = 1e9+7;
         for(int k = 0; k < V; k++){
             for(int i = 0; i < V; i++){
                for(int j = 0; j < V; j++){
                    // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && 
                       dist[i][k] + dist[k][j] < dist[i][j]){
                            dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
         }
    }
  
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = cost.size();
        vector<vector<long long int>>dist(26,vector<long long int>(26,INT_MAX));
        for(int i=0;i<n;i++){
            long long int x = cost[i];
            dist[original[i]-'a'][changed[i]-'a'] = min(dist[original[i]-'a'][changed[i]-'a'],x);
        }
        floydWarshall(dist);
        int m = target.size();
        long long int result = 0;
        for(int i=0;i<m;i++){
            if(source[i]!=target[i]){
                long long int res = dist[source[i]-'a'][target[i]-'a'];
                if(res>=INT_MAX)return -1;
                result += res;
            }
        }
        return result;
    }
};