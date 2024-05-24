class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = 0;
        int j = 0 , n = nums.size();
        int zero = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)++zero;
            while(j<=i&&zero>k){
                if(nums[j]==0)--zero;
                j++;
            }
            len = max(len,(i-j)+1);
        }
        return len;
    }
};