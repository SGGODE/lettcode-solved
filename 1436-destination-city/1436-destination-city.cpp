class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,vector<string>>mp;
        for(auto&it:paths){
            mp[it[0]].push_back(it[1]);
        }
        for(auto&it:paths){
            if(!mp.count(it[1]))return it[1];
        }
        return "-1";
    }
};