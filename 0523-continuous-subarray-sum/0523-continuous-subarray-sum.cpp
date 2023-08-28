class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<long long int,long long int>mp;
        long long int sum=0;
        //mp[sum]++;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)++cnt;
            else{
                cnt=0;
            }
            if(cnt>=2)return 1;
            sum=(long long)sum+nums[i];
            if(sum>=k&&sum%k==0&&i>=1)return 1;
            if(sum>=k&&mp.count(sum%k)&&(i-mp[sum%k])>=2){
                return 1;
            }
            if(!mp.count(sum%k))mp[sum%k]=i;
        }
        return 0;
    }
};