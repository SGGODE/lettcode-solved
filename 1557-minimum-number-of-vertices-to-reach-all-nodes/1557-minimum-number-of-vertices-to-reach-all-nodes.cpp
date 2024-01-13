class Solution {
private:
    int sub(vector<int>adj[],map<int,int>&mp,int src){
        //if(mp.count(src))return mp[src];
        int ans = 0;
        for(auto&it:adj[src]){
            ans += (1+sub(adj,mp,it)); 
        }
        mp[src]=ans;
        return ans;
    }
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
      map<int,int>mp;
      vector<int>adj[n];
      for(auto&it:edges){
          adj[it[0]].push_back(it[1]);
          mp[it[1]]++;
      }
      int len = 0;
        vector<int>res;
      for(int i=0;i<n;i++){
         if(!mp.count(i))res.push_back(i);
      }
      return res;
    }
};