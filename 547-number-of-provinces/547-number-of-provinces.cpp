class Solution {
private:
    void dfs(vector<int> adj[],int node,vector<bool>&arr){
        arr[node]=1;
        for(auto it:adj[node]){
            if(!arr[it])
                dfs(adj,it,arr);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> v[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1&&i!=j){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
       vector<bool>arr(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!arr[i]){
                cnt++;
                dfs(v,i,arr);
            }
        }
        return cnt;
    }
};