class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
       map<int,int>mx;
       int len = 0;
       int j = 0;
       for(int i=0;i<nums.size();i++){
           mx[nums[i]]++;
           if(mx[nums[i]]>k){
               while(j<i&&mx[nums[i]]>k){
                   --mx[nums[j]];
                   if(mx[nums[j]]==0)mx.erase(nums[j]);
                   j++;
               }
           }
           len = max(len,(i-j)+1);
       }
      return len;
    }
};