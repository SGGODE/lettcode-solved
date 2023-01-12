// class Solution {
// private:
//     void dfs(vector<int>adj[],int index,vector<bool>&vis,int &sum,char target,string labels){
//         if(vis[index])return;
//          vis[index]=1;
//        // cout<<1<<sum<<" "<<target<<" "<<endl;
//         //cout<<target<<endl;
//         for(auto it:adj[index]){
//             if(labels[it]==target&&!vis[it]){
//                 ++sum;
//                 cout<<sum<<" "<<target<<" "<<it<<endl;
//             }
//             if(!vis[it])
//             dfs(adj,it,vis,sum,target,labels);
//         }
//     }
// public:
//     vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
//         vector<int>adj[n];
//         for(int i=0;i<edges.size();i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
//         // vector<int>::iterator vt;
//         // for(int i=0;i<n;i++){
//         //     for(auto it:adj[i]){
//         //         vt=find(adj[it].begin(),adj[it].end(),i);
//         //         if(vt==adj[it].end())adj[it].push_back(i);
//         //     }
//         // }
//         for(auto it:adj){
//            // cout<<it<<" ";
//             for(auto vt:it)cout<<vt<<" ";
//             cout<<endl;
//         }
//         vector<int>res(n,-1);vector<bool>vis(n,0); 
//         for(int i=0;i<n;i++){
//            int sum=1;
//           // vis[i]=1;
//            //if(vis)
//            dfs(adj,i,vis,sum,labels[i],labels);
//            res[i]=sum;
//         }
//         return res;
//     }
// };
class Solution {
public:
  vector<int> fun(vector<vector<int>> &adj, string &labels, int i,vector<int>&result){
    vector<int> ans(26, 0);
    result[i] = 1;
    ans[labels[i] - 'a'] = 1;
    
    for(int j = 0; j != adj[i].size(); j++)
      if(!result[adj[i][j]]){
        vector<int> tmp = fun(adj, labels,adj[i][j],result);
        for(int k = 0; k != 26; k++) ans[k] += tmp[k];
      }
    
    result[i] = ans[labels[i] - 'a'];
    
    return ans;
  }
  
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<vector<int>> adj(n);
    vector<int> result(n,0);
    for(int i = 0; i != edges.size(); i++)
     {adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
     }
    
    fun(adj, labels, 0,result);
    return result;
  }
};