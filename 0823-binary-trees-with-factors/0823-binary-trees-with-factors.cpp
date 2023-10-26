class Solution {
public:
    int numFactoredBinaryTrees(vector<int>&nums) {
        long long res = 0;
        int mod = 1e9+7;
        map<int,long long>mp;
        sort(nums.begin(),nums.end());
        mp[nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            long long count = 1;
            for(auto&it:mp){
                if(nums[i]%it.first==0&&mp.count(nums[i]/it.first)){
                    count += (mp[it.first]*mp[nums[i]/it.first]);
                }
            }
            mp[nums[i]]=count;
        }
        for(auto&it:mp){
            res = (res+it.second)%mod;
        }
        return res;
    }
};