class Solution {
private:
//     void dfs(vector<int>adj[],vector<bool>&vis,unordered_map<int,int>&mp,int src,bool&flag,int start){
//       queue<int>pq;
//       pq.push(src);
//       while(!pq.empty()){
//           if(adj[pq.top()].empty()){
//               pq.pop();
//               flag=1;
//           }else{
              
//           }
//       }  
//     }
     // void dfs(vector<int>adj[],vector<bool>&vis,int src,bool&flag){
     //    if(vis[src])return;
     //    vis[src]=1;
     //    for(auto it:adj[src]){
     //        if(vis[it]){
     //            flag=1;
     //        }
     //        dfs(adj,vis,it,flag);
     //    }
     //    vis[src]=0;
//     //}
//      bool dfs(vector<int> adj[],int node,vector<bool>&arr,vector<int>&stack){
//       stack[node]=1;
    
//     //  if(!arr[node]){
//           arr[node]=1;
//           for(auto it:adj[node]){
//               if(!arr[it])dfs(adj,it,arr,stack);
//               //  return 1;
//               if(stack[it])
//                 return 1;
//           }
//     //  }
//      stack[node]=0;
//     return 0;
// }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
       // vector<int>res;
        vector<int>adj[n+1];
        for(int i=0;i<n;i++){
            if(!graph[i].empty()){
            for(auto it:graph[i]){
                adj[it].push_back(i);
              }
            }
        }
      //   // for(int i=0;i<n;i++){
      //   //     for(auto it:adj[i])cout<<it<<" ";
      //   //     cout<<endl;
      //   // }
      //   unordered_map<int,int>mp;
      //   for(int i=0;i<n;i++){
      //       if(graph[i].empty()){
      //           res.push_back(i);
      //           mp[i]++;
      //          // cout<<i<<endl;
      //       }
      //   }
      // //  cout<<adj[4].size()<<endl;
      //    vector<bool>vis(n,0);
      //    vector<int>stack(n,0);
      //   for(int i=0;i<n;i++){
      //       if(adj[i].empty()){
      //          continue;
      //       }else{
      //           int cnt=0;
      //           bool flag=0;
      //           if(dfs(adj,i,vis,stack)){
      //               res.push_back(i);
      //           }
      //       }
      //   }
      //   sort(res.begin(),res.end());
      //   return res;
       vector<int>indegre(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i])indegre[it]++;
        }
        queue<int>pq;
        for(int i=0;i<n;i++){
            if(indegre[i]==0)pq.push(i);
        }
        set<int>s;
        while(!pq.empty()){
           int temp=pq.front();
            pq.pop();
            s.insert(temp);
            for(auto it:adj[temp]){
                --indegre[it];
                if(indegre[it]==0)pq.push(it);
            }
        }
        vector<int>res(s.begin(),s.end());
        return res;
    }
};