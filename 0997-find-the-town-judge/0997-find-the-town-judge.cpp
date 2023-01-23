class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>adj[n+1];
        for(int i=0;i<trust.size();i++){
            adj[trust[i][0]].push_back(trust[i][1]);
        }
        for(int i=1;i<=n;i++){
            if(adj[i].empty()){
                bool flag=1;vector<int>::iterator it;
               for(int j=1;j<=n;j++){
                   if(j==i)continue;
                   else{
                   it=find(adj[j].begin(),adj[j].end(),i);
                   if(it==adj[j].end()){
                       flag=0;
                    }
                  }
               }
                if(flag)
                return i;
            }
        }
        return -1;
    }
};