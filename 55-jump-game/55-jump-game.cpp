class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 1;
        int temp=0;
        for(int i=0;i<n-1;i++){
         temp=max(temp,i+nums[i]);
            if(temp>=n-1)
                return 1;
            if(temp==i)
                return 0;
        }
        return 0;
    }
};