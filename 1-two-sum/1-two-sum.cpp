class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
           int sum=target-nums[i];
            if(mp.find(sum)!=mp.end()){
                return {mp[sum],i};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};