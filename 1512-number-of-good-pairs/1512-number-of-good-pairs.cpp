class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i]))cnt+=mp[nums[i]];
            mp[nums[i]]++;
        }
        return cnt;
    }
};