class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(i>=1&&nums[i]<=nums[i-1]){
                sum+=(nums[i-1]-nums[i])+1;
                nums[i]=nums[i-1]+1;
            }
        }
        return sum;
    }
};