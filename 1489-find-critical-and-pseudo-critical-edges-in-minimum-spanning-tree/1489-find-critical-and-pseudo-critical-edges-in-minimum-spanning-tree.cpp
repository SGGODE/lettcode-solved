// class Solution {
// private:
//    pair<int,set<int>> sum(set<pair<vector<int>,int>>&res,int n){
//     vector<pair<pair<int,int>,int>>adj[n+1];
//     int start=-1;
//     int index=-1;
//     for(auto&it:res){
//         start=it.first[0];
//         index=it.second;
//         adj[it.first[0]].push_back({{it.first[1],it.first[2]},it.second});
//         adj[it.first[1]].push_back({{it.first[0],it.first[2]},it.second});
//     }
//     priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>pq;
//    // if(index!=0)pq.push({{0,0},0});
//    //  if(index==0)pq.push({{0,1},1});
//     pq.push({{0,start},index});  
//     int sum=0;
//     set<int>nodes;
//     vector<bool>vis(n,0);
//     while(!pq.empty()){
//       int node = pq.top().first.second;
//       int dist = pq.top().first.first;
//       int index = pq.top().second;
//       pq.pop();
//       if(vis[node]==1)continue;
//       sum+=dist;
//       nodes.insert(index);
//       vis[node]=1;
//       for(auto&it:adj[node]){
//         if(!vis[it.first.first]){
//           pq.push({{it.first.second,it.first.first},it.second});
//         }
//       }
//     }
//      return {sum,nodes};
//     }
// public:
//     vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
//         if(edges.size()==1){
//             return {{0},{}};
//         }
//         set<pair<vector<int>,int>>res;
//         for(int i=0;i<edges.size();i++){
//             res.insert({edges[i],i});
//         }
//         vector<int>critical;
//         vector<vector<int>>output;
//         //set<int>carry;
//         auto rsum = sum(res,n);
//         int resum = rsum.first;
//         set<int>carry = rsum.second;
//         for(int i=0;i<edges.size();i++){
//             res.erase({edges[i],i});
//             auto function = sum(res,n);
//             int currsum = function.first;
//             set<int>nums = function.second;
//             bool flag=1;
//             set<int>value;
//             for(auto&it:nums){
//               //  cout<<it<<" ";
//                 value.insert(edges[it][0]);value.insert(edges[it][1]);
//             }//cout<<endl;
//             for(int i=0;i<n;i++){
//                 if(value.find(i)==value.end()){
//                     flag=0;
//                    // cout<<i<<endl;
//                 }
//             }
//             if(currsum>resum||!flag){
//                 critical.push_back(i);
//             }
//             if(currsum==resum){
//                 for(auto&it:nums)carry.insert(it);
//             }
//             res.insert({edges[i],i});
//         }
//         for(auto&it:critical)carry.erase(it);
//         output.push_back(critical);
//         vector<int>temp;
//         for(auto&it:carry)temp.push_back(it);
//         output.push_back(temp);
//         return output;
//     }
// };
struct DSU{
    int parent[101];
    int size[101];
    DSU(int n){
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    bool unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return false;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return true;
    }
};
int sz;
class Solution {
private:
    int kruskal(vector<vector<int>>& edges, int n, int skip, int pick){
        DSU dsu(n);
        int sum = 0;

        if(pick > -1){
            dsu.unionBySize(edges[pick][0],edges[pick][1]);
            sum += edges[pick][2];
            n--;
        }

        for(int i=0; i<sz; i++){
            if(skip == i) continue;
            int u = edges[i][0];
            int v = edges[i][1];

            if(dsu.unionBySize(u,v)){
                sum += edges[i][2];
                n--;
            }
        }
        
        if(n == 1) return sum;
        return 1e9;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        sz = edges.size();
        for(int i=0; i<sz; i++){
            edges[i].push_back(i);
        }
        auto comp = [&](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        };
        sort(edges.begin(),edges.end(),comp);

        int mst_wt = kruskal(edges,n,-1,-1);

        vector<int> critical;
        vector<int> pseudo;
        for(int i=0; i<sz; i++){

            if(kruskal(edges,n,i,-1) > mst_wt){
                critical.push_back(edges[i][3]);
            }
            else if(kruskal(edges,n,-1,i) == mst_wt){
                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical,pseudo};
    }
};