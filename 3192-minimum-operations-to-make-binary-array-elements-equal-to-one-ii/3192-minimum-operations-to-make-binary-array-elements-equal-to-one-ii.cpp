class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size(),one = 0,cnt = 0;
        for(int i=n-1;i>=0;i--){
            int j = i;
            while(j>=0&&nums[j]==0)j--;
            if(j!=i){
                if(one)cnt+=2;
                else ++cnt;
                i=j+1;
            }
            if(nums[i])++one;
        }
        return cnt;
    }
};