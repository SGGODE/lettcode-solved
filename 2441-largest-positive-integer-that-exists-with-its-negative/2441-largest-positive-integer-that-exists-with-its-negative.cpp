class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int>mp;
        int res = -1;
        for(auto&it:nums)mp[it]++;
        for(auto&it:nums){
            if(it>0&&mp.count(-it))res=max(res,it);
        }
        return res;
    }
};