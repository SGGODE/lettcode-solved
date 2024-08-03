class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& a) {
         unordered_map<int,int>mp,cp;
         for(auto&it:t)mp[it]++;
         for(auto&it:a)cp[it]++;
         return mp==cp;
    }
};