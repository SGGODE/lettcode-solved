class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size() , msum = 1e9;
        for(int i = 0; i < n; i++){
            int sum = 0;
           for(int j = i; j < n; j++){
               sum += nums[j];
               if((j-i)+1 >= l && (j-i)+1 <= r && sum > 0)msum = min(msum , sum);
           }  
        }
        return msum == 1e9 ? -1 : msum ;
    }
};