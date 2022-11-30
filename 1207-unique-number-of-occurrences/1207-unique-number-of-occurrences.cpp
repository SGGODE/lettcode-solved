class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(auto it:arr)mp[it]++;
        map<int,int>mx;
        for(auto it:mp){
            mx[it.second]++;
        }
        for(auto it:mx){
            if(it.second>1)return 0;
        }
        return 1;
    }
};