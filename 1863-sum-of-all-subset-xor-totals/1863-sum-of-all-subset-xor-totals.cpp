class Solution {
private:
    int sub(vector<int>&nums,int index,int Xor){
        if(index==nums.size())return Xor;
        int ans = 0;
        ans += sub(nums,index+1,Xor);
        ans += sub(nums,index+1,Xor^nums[index]);
        return ans;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return sub(nums,0,0);
    }
};