class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int idx=0,n=nums.size();
        if(n==1)
            return 0;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]){
                return i;
            }
        }
        if(nums[nums.size()-1]>nums[nums.size()-2]&&nums[nums.size()-1]>nums[0]){
            return nums.size()-1;
        }
        return 0;
    }
};