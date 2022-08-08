class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
      int m=0,r=0;
       map<int,int>s; 
        int c=0;
        vector<pair<int,int>>edge;
        for(int i=0;i<edges.size();i++){
            int j=0;
            edge.push_back(make_pair(edges[i][0],edges[i][1]));
        }
        for(int i=0;i<edge.size();i++){
           s[edge[i].first]++;
           s[edge[i].second]++;
          }
    for(auto it:s){
        if(m<it.second){
           m=it.second;
           r=it.first;
     }
    }
        return r;
    }
};