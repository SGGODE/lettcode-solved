class Solution {
public:
    bool check(vector<int>& nums) {
       int k=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])
                k++;
        }
        if(nums[nums.size()-1]>nums[0])
            k++;
        return k<=1;
    }
};