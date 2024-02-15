class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
       long long sum = 0;
       int n = nums.size();
       sort(nums.begin(),nums.end());
       vector<long long>prefix;
       for(auto&it:nums){
           sum+=it;
           prefix.push_back(sum);
       }
       long long res = -1;
       for(int i=2;i<n;i++){
           if(prefix[i-1]>nums[i]){
               res = max(res,prefix[i]);
           }
       }
      return res;
    }
};