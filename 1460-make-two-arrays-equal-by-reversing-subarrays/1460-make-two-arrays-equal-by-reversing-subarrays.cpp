class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& a) {
         unordered_map<int,int>mp;
         for(auto&it:t)mp[it]++;
         for(auto&it:a){
             if(!mp.count(it))return 0;
             --mp[it];
             if(mp[it]==0)mp.erase(it);
         }
         return mp.empty();
    }
};