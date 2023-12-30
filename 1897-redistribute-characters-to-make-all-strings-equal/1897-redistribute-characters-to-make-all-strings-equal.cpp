class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int>mp;
        for(auto&it:words){
            for(auto vt:it)mp[vt]++;
        }
        int n = words.size();
        for(auto&it:mp){
            if(it.second%n!=0)return 0;
        }
        return 1;
    }
};