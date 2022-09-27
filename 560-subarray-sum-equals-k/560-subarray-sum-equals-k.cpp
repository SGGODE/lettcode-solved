class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       map<int,int>mp;
       int sum=0,n=nums.size();
        int ans=0;
        mp[sum]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};