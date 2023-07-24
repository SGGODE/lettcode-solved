class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        map<int,int>mp;
        mp[sum]++;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.count(sum-k)){
                cnt+=mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};