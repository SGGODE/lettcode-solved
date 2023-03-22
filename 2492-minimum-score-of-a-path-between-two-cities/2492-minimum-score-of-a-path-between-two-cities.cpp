class Solution {
private:
    void check(vector<pair<int,int>>adj[],int n,int start,vector<int>&v,vector<bool>&vis){
        if(vis[start])return;
        vis[start]=1;
        for(auto it:adj[start]){
            if(it.first==n){
                v.push_back(it.second);
                 check(adj,n,it.first,v,vis);
               // return;
            }else{
                v.push_back(it.second);
                check(adj,n,it.first,v,vis);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<roads.size();i++){
           adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
           adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        // for(auto it:adj){
        //     for(auto vt:it)cout<<vt.first<<" "<<vt.second<<" ";
        // }
        vector<int>v;
        vector<bool>vis(n,0);
        check(adj,n,1,v,vis);
        return *min_element(v.begin(),v.end());
       // return 5;
    }
};