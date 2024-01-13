class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp,mx;
        for(auto&it:s)mp[it]++;
        for(auto&it:t)mx[it]++;
        if(mp==mx)return 0;
        int cnt = 0;
        for(auto&it:mp){
            if(mx.count(it.first)&&it.second>mx[it.first]){
                cnt += abs(mx[it.first]-it.second);
            }else if(!mx.count(it.first)){
                cnt += it.second;
            }
        }
        return cnt;
    }
};