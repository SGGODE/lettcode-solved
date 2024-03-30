# class Solution {
# private:
#     map<pair<int,pair<pair<int,int>,int>>,int>dp;
#     int mod =1e9+7;
#     int sub(vector<int>&nums,int index,int k,int last,int diff){
#         if(k==0)return diff;
#         if(index==nums.size())return 0;
#         if(dp.count({index,{{k,last},diff}}))return dp[{index,{{k,last},diff}}];
#         int ans = sub(nums,index+1,k,last,diff)%mod;
#         if(last!=-1){
#             ans = (ans+ sub(nums,index+1,k-1,index,min(diff,abs(nums[last]-nums[index]))))%mod;
#         }else{
#            ans = (ans + sub(nums,index+1,k-1,index,diff))%mod;  
#         }
#         return dp[{index,{{k,last},diff}}]=ans%mod;
#     }
# public:
#     int sumOfPowers(vector<int>& nums, int k) {
#         sort(nums.begin(),nums.end());
#         return sub(nums,0,k,-1,1e9)%mod;
#     }
# };
class Solution:
    def __init__(self):
        self.dp = {}
        self.mod = 10**9 + 7

    def sub(self, nums, index, k, last, diff):
        if k == 0:
            return diff
        if index == len(nums):
            return 0
        if (index, (k, last), diff) in self.dp:
            return self.dp[(index, (k, last), diff)]

        ans = self.sub(nums, index + 1, k, last, diff) % self.mod

        if last != -1:
            new_diff = min(diff, abs(nums[last] - nums[index]))
            ans = (ans + self.sub(nums, index + 1, k - 1, index, new_diff)) % self.mod
        else:
            ans = (ans + self.sub(nums, index + 1, k - 1, index, diff)) % self.mod

        self.dp[(index, (k, last), diff)] = ans % self.mod
        return ans % self.mod

    def sumOfPowers(self, nums: List[int], k: int) -> int:
        nums.sort()
        return self.sub(nums, 0, k, -1, 10**9) % self.mod

    