class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
       int n = nums.size();
       int mx = *max_element(nums.begin(),nums.end());
       long long ans = 0;
       int j=0,i=0;
       map<int,int>mp;
       while(i<n){
           mp[nums[i]]++;
           while(j<=i&&mp[mx]>=k){
               ans += (n-i);
               --mp[nums[j]];
               j++;
           }
           i++;
       }
       return ans;
    }
};