class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       map<int,int>mp;
       int sum = 0;
       int mlen = 0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]==1)sum+=1;
           else sum-=1;
           if(sum==0)mlen=i+1;
           if(mp.count(sum)){
               mlen = max(mlen,i-mp[sum]);
           }else{
               mp[sum]=i;
           }
       }
        return mlen;
    }
};