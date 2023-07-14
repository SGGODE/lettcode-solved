class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp,mx;
        for(auto&it:s)mp[it]++;
        for(auto&it:t)mx[it]++;
        int cnt=0;
        for(auto&it:mp){
            if(mx.count(it.first)){
                if(it.second>mx[it.first])cnt+=abs(it.second-mx[it.first]);
            }else{
                cnt+=it.second;
            }
        }
        return cnt;
    }
};