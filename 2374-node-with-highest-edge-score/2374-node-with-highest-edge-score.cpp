class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long> v(edges.size());
        for(int i=0;i<edges.size();i++){
            v[edges[i]]+=i;
        }
        return max_element(begin(v),end(v))-begin(v);
    }
};