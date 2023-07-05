class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cnt=0;int j=0;
            if(len>=(n-i))break;
            for(j=i;j<n;j++){
                if(cnt==1&&nums[j]==0){
                    len=max(len,(j-i)-1);
                    break;
                }
                if(nums[j]==0)++cnt;
            }
            len=max(len,(j-i)-1);
        }
        return len;
    }
};