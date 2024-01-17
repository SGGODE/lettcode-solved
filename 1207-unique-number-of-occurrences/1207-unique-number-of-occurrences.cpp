class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(auto&it:arr)mp[it]++;
        set<int>s;
        for(auto&it:mp){
            if(s.count(it.second))return 0;
            s.insert(it.second);
        }
        return 1;
    }
};