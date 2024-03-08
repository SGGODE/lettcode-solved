class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        int mlen = 0;
        for(auto&it:nums){
            mp[it]++;
            mlen = max(mlen,mp[it]);
        }
        int cnt = 0;
        for(auto&it:mp){
            if(it.second==mlen)++cnt;
        }
        return cnt * mlen;
    }
};