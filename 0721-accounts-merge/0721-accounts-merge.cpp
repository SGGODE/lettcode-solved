class DisjointSet{
  vector<int>rank,parent,size;
public:
  DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++)parent[i]=i;
    for(int i=0;i<=n;i++)size[i]=1;
  }
  int findPar(int child){
    if(child==parent[child])return child;
    return parent[child]=findPar(parent[child]);
  }
  void unionbyrank(int u,int v){
    int par_u = findPar(u);
    int par_v = findPar(v);
    if(par_u==par_v)return;
    if(rank[par_u]<rank[par_v]){
      parent[par_u]=par_v;
    }else if(rank[par_v]<rank[par_u]){
      parent[par_v]=par_u;
    }else{
      parent[par_u]=par_v;
      rank[par_v]++;
    }
  }
  void unionbysize(int u,int v){
    int par_u = findPar(u);
    int par_v = findPar(v);
    if(par_u==par_v)return;
    if(size[par_u]<size[par_v]){
      parent[par_u]=par_v;
      size[par_v]+=size[par_u];
    }else{
      parent[par_v]=par_u;
      size[par_u]+=size[par_v];
    }
  }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>&nums) {
        int n = nums.size();
        DisjointSet ds(n+1);
        map<string,int>mp;
        vector<vector<string>>res(n);
        for(int i=0;i<nums.size();i++){
           //res[i].push_back(nums[i][0]);
            for(int j=1;j<nums[i].size();j++){
                if(mp.count(nums[i][j])){
                    ds.unionbyrank(mp[nums[i][j]],i);
                }else{
                    mp[nums[i][j]]=i;
                }
            }
        }
        for(auto&it:mp){
            int par=ds.findPar(it.second);
            res[par].push_back(it.first);
        }
        vector<vector<string>>temp;
        for(int i=0;i<n;i++){
            if(!res[i].empty()){
                res[i].insert(res[i].begin(),nums[i][0]);
                temp.push_back(res[i]);
            }
        }
        sort(temp.begin(),temp.end());
        // for(int i=0;i<n;i++){
        //     sort(res[i].begin()+1,res[i].end());
        //     //for(auto vt:it)cout<<vt<<" ";
        //     //cout<<endl;
        // }
        return temp;
    }
};