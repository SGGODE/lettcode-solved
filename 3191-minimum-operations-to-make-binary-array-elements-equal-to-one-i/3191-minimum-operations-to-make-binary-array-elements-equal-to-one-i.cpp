class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n-2; i++){
            if(!nums[i]){
                ++count;
                nums[i]=1;
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
            }
        }
        return (nums[n-1]&nums[n-2])?count:-1;
    }
};