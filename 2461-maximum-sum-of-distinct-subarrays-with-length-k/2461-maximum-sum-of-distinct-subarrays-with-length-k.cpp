class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size() , j = 0;
        long long sum = 0 , ans = 0;
        unordered_map<int , int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            sum += nums[i];
            if((i+1) >= k){
                while((1+(i-j)) > k){
                    sum -= nums[j];
                    --mp[nums[j]];
                    if(mp[nums[j]] == 0)mp.erase(nums[j]);
                    j++;
                }
            }
            if(mp.size() == k)ans = max(ans , sum);
        }
        return ans;
    }
};