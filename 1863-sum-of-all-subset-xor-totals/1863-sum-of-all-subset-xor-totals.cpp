class Solution {
private:
    int dp[13][100];
    int sub(vector<int>&nums,int index,int Xor){
        if(index==nums.size())return Xor;
        if(dp[index][Xor]!=-1)return dp[index][Xor];
        int ans = 0;
        ans += sub(nums,index+1,Xor);
        ans += sub(nums,index+1,Xor^nums[index]);
        return dp[index][Xor]=ans;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return sub(nums,0,0);
    }
};