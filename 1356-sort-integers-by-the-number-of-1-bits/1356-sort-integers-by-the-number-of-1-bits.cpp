class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>>mp;
        for(auto&it:arr){
            int cnt = 0;
            int num = it;
            while(num){ 
             if(num & 1)++cnt;
             num>>=1;
            } 
            mp[cnt].push_back(it);
            sort(mp[cnt].begin(),mp[cnt].end());
        }
        vector<int>result;
        for(auto&it:mp){
            for(auto vt:it.second)result.push_back(vt);
        }
        return result;
    }
};