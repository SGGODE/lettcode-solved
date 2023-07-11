class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int len=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(len>=(n-i))return len;
            int j=i;int m=nums[i];int mx=nums[i];
            while(j<n&&abs(m-mx)<=limit){
                ++j;
                if(j<n){
                    m=min(nums[j],m);
                    mx=max(nums[j],mx);
                }
            }
            len=max(len,(j-i));
        }
        return len;
    }
};