class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(auto&it:nums)mp[it]++;
        int n = nums.size();
        vector<int>res;
        for(auto&it:mp){
            if(it.second>n/3)res.push_back(it.first);
        }
        return res;
    }
};