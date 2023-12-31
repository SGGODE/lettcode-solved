class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0)return {};
        map<int,int>mp,dump;
        for(auto&it:changed){
            mp[it]++;
        }
        vector<int>res;
        sort(changed.begin(),changed.end());
        for(auto&it:changed){
           if(it==0&&mp[it]==1)return {};
           else if(mp[it]>0&&mp[2*it]>0){
               --mp[it];
               --mp[2*it];
               res.push_back(it);
           }
        }
        if(res.size()*2!=changed.size())return {};
        return res;
    }
};