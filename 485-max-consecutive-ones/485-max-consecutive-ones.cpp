class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
         int sw=0;
        int cnt=0;
        for(int i=0;i<n;i++){
           if(nums[i]==1)
               sw=max(++cnt,sw);
            else
                cnt=0;
        }
        return sw;
    }
};