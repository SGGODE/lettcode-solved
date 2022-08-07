class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
       map<int,int>f;
        for(auto i:items1){
           f[i[0]]+=i[1];
        }
        for(auto i :items2){
            f[i[0]]+=i[1];
        }
        vector<vector<int>> v;
        for(auto i:f){
            v.push_back({i.first,i.second});
        }
        return v;
    }
};