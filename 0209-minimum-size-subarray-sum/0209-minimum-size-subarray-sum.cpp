class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int i=0,j=0;
        int len = 1e9;
        while(i<n){
            sum+=nums[i];
            while(j<=i&&sum>=k){
                len = min(len,(i-j)+1);
                sum-=nums[j];
                j++;
            }
            i++;
        }
        return len==1e9?0:len;
    }
};