class Solution {
private:
//     void dfs(int index,vector<pair<int,int>>adj[],int dist,vector<bool>&vis,int myindex){
//        if(vis[index]==1)return;
//        vis[index]=1;
//        vector<pair<int,int>>::iterator vt;
//         for(auto it:adj[index]){
//           vt=find(adj[myindex].begin(),adj[myindex].end(),it);
//           if(vt==adj[myindex].end()){
//             adj[myindex].push_back({it.first,dist});
//           }
//             dfs(it.first,adj,dist+1,vis,myindex);
//         }
//     }
public:
//     int closestMeetingNode(vector<int>& edges, int node1, int node2) {
//         if(node1==node2)return 0;
//         vector<int>::iterator it;
//         int n=edges.size();
//         vector<pair<int,int>>adj[n];
//         for(int i=0;i<n;i++){
//             if(edges[i]==-1)continue;
//             else{
//                 adj[i].push_back({edges[i],1});
//                 //adj[edges[i]].push_back(i);
//             }
//         }
//         // adj[node1].push_back({node1,0});
//         //  adj[node2].push_back({node2,0});
//         // for(auto it:adj[node1])cout<<it.first<<" "<<it.second<<" ";
//         // cout<<endl;
//          vector<bool>vis(n,0);
//          dfs(node1,adj,1,vis,node1);
//         // for(auto it:adj[node2])cout<<it.first<<" "<<it.second<<" ";
//         // cout<<endl;
//          vector<bool>vis1(n,0);
//         dfs(node2,adj,1,vis1,node2);
//         //   for(auto it:adj[node2])cout<<it.first<<" "<<it.second<<" ";
//         // cout<<endl;
//         if(edges[node1]==-1&&edges[node2]==-1)return -1;
//         else if(edges[node1]==-1&&edges[node2]!=-1){
//             for(auto it:adj[node2]){
//                 if(it.first==node1)return it.second;
//             }
//         }else if(edges[node1]!=-1&&edges[node2]==-1){
//             for(auto it:adj[node1]){
//                 if(it.first==node2)return it.second;
//             }
//         }
//         vector<pair<int,int>>v;
//         vector<pair<int,int>>::iterator vt;
//         for(auto it:adj[node1]){
//          //  vt=find(adj[node2].begin(),adj[node2].end(),it);
//          //  if(vt==adj[node2].end())continue;
//          //  else{
//                int x=it.second;
//                for(auto xt:adj[node2]){
//                    if(xt.first==it.first){
//                        x=max(x,xt.second);
//                    }
//                }
//                v.push_back({x,it.first});
//            // }
//         }
//          sort(v.begin(),v.end());
//          return v[0].second;
//         return 2;
//     }
    void dfs(int i, int dist, vector<int>& e, vector<int>& memo) {
    while (i != -1 && memo[i] == -1) {
        memo[i] = dist++;
        i = e[i];
    }
}
int closestMeetingNode(vector<int>& e, int node1, int node2) {
    int res = -1, min_dist = INT_MAX;
    vector<int> m1(e.size(), -1), m2(e.size(), -1);
    dfs(node1, 0, e, m1);
    dfs(node2, 0, e, m2);
    for (int i = 0; i < e.size(); ++i)
        if (min(m1[i], m2[i]) >= 0 && max(m1[i], m2[i]) < min_dist) {
            min_dist = max(m1[i], m2[i]);
            res = i;
        }
    return res;
}
 };