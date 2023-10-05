class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(auto&it:nums)mp[it]++;
        vector<int>res;
        for(auto&it:mp){
            if(it.second>n/3)res.push_back(it.first);
        }
        return res;
    }
};