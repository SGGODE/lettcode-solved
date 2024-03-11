class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>mp;
        for(auto&it:s)mp[it]++;
        string result;
        for(auto&it:order){
            if(mp.count(it)){
                for(int i=0;i<mp[it];i++)result.push_back(it);
                mp.erase(it);
            }
        }
        for(auto&it:mp){
            for(int i=0;i<it.second;i++)result.push_back(it.first);
        }
        return result;
    }
};