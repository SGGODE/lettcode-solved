class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        for(auto&it:arr)mp[it]++;
        vector<pair<int,int>>res;
        for(auto&it:mp){
            res.push_back({it.second,it.first});
        }
        sort(res.begin(),res.end());
        for(int i=0;i<res.size()&&k!=0;i++){
            if(k>=res[i].first){
                k -= res[i].first; 
                res[i].first=0;
            }else{
                res[i].first=(res[i].first-k);
                k=0;
            }
         }
        int cnt = 0;
         for(int i=0;i<res.size();i++){
             if(res[i].first>0)++cnt;
         }
        return cnt;
    }
};


