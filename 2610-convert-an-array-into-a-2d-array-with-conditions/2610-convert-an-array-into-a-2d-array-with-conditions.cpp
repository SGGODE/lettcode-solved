class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>mp;
        int len = 0;
        for(auto&it:nums){
            mp[it]++;
            len = max(len,mp[it]);
        }
        vector<vector<int>>res(len);
        for(auto&it:mp){
            int index = 0;int cnt = it.second;
            while(cnt!=0){
                res[index].push_back(it.first);
                ++index;
                --cnt;
            }
        }
        return res;
    }
};