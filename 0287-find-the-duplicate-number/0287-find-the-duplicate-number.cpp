class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(auto&it:nums){
            if(mp.count(it))return it;
            mp[it]++;
        }
        return -1;
    }
};