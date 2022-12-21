// class Solution {
// public:
//     bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
//         if(n==1)return 1;
//         // set<int>s;
        // for(auto it:dislikes){
        //     for(auto vt:it)s.insert(vt);
        // }
        // // map<int,int>mp;
        // // for(auto it:s)mp[it]++;
        // //  for(auto it:mp)cout<<it.first<<" ";
        // //  cout<<endl;
        // vector<int>adj[n];
        // for(int i=0;i<dislikes.size();i++){
        //     adj[dislikes[i][0]].push_back(dislikes[i][1]);
        // }
        // // for(auto it:adj){
        // //     for(auto vt:it)cout<<vt<<" ";
        // //     cout<<endl;
        // // }
        //  vector<int>dump;
        // // for(auto it:mp){
        // //     if((adj[it.first].empty()))continue;
        // //     for(auto vt:adj[it.first]){
        // //        cout<<vt<<" ";
        // //         if(mp.find(vt)!=mp.end()){
        // //             mp.erase(vt);
        // //            dump.push_back(vt);
        // //         }
        // //     }
        // // }
        // //  for(auto it:mp)cout<<it.first<<" map ";
        // //  cout<<endl;
        // //  for(auto it:dump)cout<<it<<" ";
        // //  cout<<endl;
        // vector<bool>vis(n,0);
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //      vis[i]=1;
        //       for(auto it:adj[i]){
        //         vis[it]=1;
        //          dump.push_back(it);
        //        }
        //     }
        // }
        // vector<bool>vis1(n,0);
        // for(int i=0;i<dump.size();i++){
        //     // if(!vis1[it]){
        //     //  vis1[it]=1;
        //   for(auto vt:adj[dump[i]]){
        //     //    vis1[vt]=1;
        //          //dump.push_back(it);
        //    }
        //     //}else return 0;
//         // }
//         map<int,int>mp,mp1;
//         for(int i=0;i<dislikes.size();i++){
//             if(mp.find(dislikes[i][0])==mp.end()&&(mp1.find(dislikes[i][0])==mp1.end())){
//                 if(mp.find(dislikes[i][1])==mp.end()&&(mp1.find(dislikes[i][1])==mp1.end())){
//                     mp[dislikes[i][0]]++;
//                     mp1[dislikes[i][1]]++;
//                 }else{
//                     if(mp.find(dislikes[i][1])==mp.end()){
//                         mp[dislikes[i][0]]++;
//                     }else{
//                         mp1[dislikes[i][0]]++;
//                     }
//                 }
//                 continue;
//             }
//             if((mp.find(dislikes[i][0])!=mp.end()||(mp1.find(dislikes[i][0])!=mp1.end()))&&
//                (mp.find(dislikes[i][1])==mp.end()&&(mp1.find(dislikes[i][1])==mp1.end()))){
//                 if(mp.find(dislikes[i][0])==mp.end()){
//                         mp[dislikes[i][1]]++;
//                     }else{
//                         mp1[dislikes[i][1]]++;
//                 }
//                 continue;
//             }
//             if((mp.find(dislikes[i][1])!=mp.end()||(mp1.find(dislikes[i][1])!=mp1.end()))&&
//                (mp.find(dislikes[i][0])==mp.end()&&(mp1.find(dislikes[i][0])==mp1.end()))){
//                 if(mp.find(dislikes[i][1])==mp.end()){
//                         mp[dislikes[i][0]]++;
//                     }else{
//                         mp1[dislikes[i][0]]++;
//                 }
//                 continue;
//             }
//             if(mp.find(dislikes[i][1])!=mp.end()||(mp.find(dislikes[i][0])!=mp.end()))return 0;
//             if(mp1.find(dislikes[i][1])!=mp1.end()||(mp1.find(dislikes[i][0])!=mp1.end()))return 0;
//         }
//         // for(auto it:mp)cout<<it.first<<" ";
//         // cout<<endl;
//         //  for(auto it:mp1)cout<<it.first<<" ";
//         // cout<<endl;
//         for(int i=1;i<=n;i++){
//             if(mp.find(i)==mp.end()&&mp1.find(i)==mp1.end())return 0;
//         }
//         return 1;
//     }
// };
class Solution {
public:
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,0);
        vector<int> adj[n+1];
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=n;i++){
            if(color[i]==0){
                color[i]=1;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int child:adj[node]){
                        if(color[child]==color[node])return false;
                        if(!color[child]){
                            q.push(child);
                            color[child]=-1*color[node];
                        }
                    }
                }
            }
        }
        
        return true;
    }
};