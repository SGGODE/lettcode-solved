class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       unordered_map<int,int>mp;
       int i=0;
       for(auto it:nums)mp[it]=i++;
       if(mp.find(target)!=mp.end())return mp[target];
       for(int i=0;i<nums.size();i++){
           if(target<nums[i])return i;
       }
        return nums.size();
    }
};