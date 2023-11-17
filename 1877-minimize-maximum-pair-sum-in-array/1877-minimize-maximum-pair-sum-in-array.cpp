class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n/2;i++){
            sum =max(sum,nums[i]+nums[n-i-1]);
        }
        return sum;
    }
};