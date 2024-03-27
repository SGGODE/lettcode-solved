class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k<=1)return 0;
        int cnt = 0;
        int right = 0,left=0;
        long long int product = 1;
        while(right<n&&left<=right){
            product *= nums[right];
            while(product>=k&&left<=right){
                    product=product/nums[left];
                    ++left;
            }
            cnt += (right-left)+1;
            ++right;
        }
        return cnt;
    }
};