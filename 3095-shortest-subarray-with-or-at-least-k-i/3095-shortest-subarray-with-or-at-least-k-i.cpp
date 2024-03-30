class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 1e9;
        for(int i=0;i<n;i++){
            int ore = 0;
            for(int j=i;j<n;j++){
                ore |= nums[j];
                if(ore>=k)len = min(len,(j-i)+1);
            }
        }
        return len>=1e9?-1:len;
    }
};