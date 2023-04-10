class Solution {
private:
    void bfs(vector<int>adj[],vector<int>&res,vector<bool>&vis,int src){
      queue<int>pq; 
       pq.push(src);
       //(n+1,0);
       while(!pq.empty()){
           int node=pq.front();
           pq.pop();
           vis[node]=1;
           bool one=0,two=0,three=0,four=0;
           for(auto it:adj[node]){
               if(!vis[it]){
                   pq.push(it);continue;
               }
               if(res[it]==1)one=1;
               if(res[it]==2)two=1;
               if(res[it]==3)three=1;
               if(res[it]==4)four=1;
           }
          // if(!one&&!two&&!three&&!four)res[node]=1;
           if(!one){
               res[node]=1;continue;
           }if(!two){
               res[node]=2;continue;
           }if(!three){
               res[node]=3;continue;
           }if(!four){
               res[node]=4;continue;
           }           
       }
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
       vector<int>res(n+1,-1);
       vector<int>adj[n+1];
       for(int i=0;i<paths.size();i++){
          adj[paths[i][0]].push_back(paths[i][1]);
          adj[paths[i][1]].push_back(paths[i][0]);
        }
        vector<bool>vis(n+1,0);
       for(int i=1;i<=n;i++){
           if(!vis[i]){
               bfs(adj,res,vis,i);
           }
       }
        vector<int>result;
        for(int i=1;i<res.size();i++){
            result.push_back(res[i]);
        }
        return result;
    }
};