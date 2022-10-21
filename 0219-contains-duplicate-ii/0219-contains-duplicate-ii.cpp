class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                int x=mp[nums[i]];
                if(abs(i-x)<=k)return 1;
            }
            mp[nums[i]]=i;
        }
        return 0;
    }
};