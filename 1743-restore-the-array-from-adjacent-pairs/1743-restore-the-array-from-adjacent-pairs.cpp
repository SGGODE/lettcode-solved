class Solution {
private:
    void dfs(int src,vector<bool>&vis,vector<bool>&neg,map<int,vector<int>>&mp,vector<int>&res){
        if(src>=0)vis[abs(src)]=1;
        if(src<0)neg[abs(src)]=1;
        res.push_back(src);
        for(auto&it:mp[src]){
            if(it>=0&&!vis[it]){
                dfs(it,vis,neg,mp,res);
            }else if(it<0&&!neg[abs(it)]){
                dfs(it,vis,neg,mp,res);
            }
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int>adj[10001];
        map<int,vector<int>>mp;
        for(auto&it:adjacentPairs){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        int start = -1;
        for(auto&it:mp){
            if(it.second.size()==1){
                start=it.first;
                break;
            }
        }
        vector<bool>vis(100001,0);
        vector<bool>neg(100001,0);
        vector<int>res;
        dfs(start,vis,neg,mp,res);
        return res;
    }
};