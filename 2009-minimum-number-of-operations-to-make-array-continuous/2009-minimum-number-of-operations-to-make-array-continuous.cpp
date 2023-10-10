class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int len = n;
        int j = 0;
        auto it=unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        int m=nums.size();
        for(int i=0;i<m;i++){
           while(j<m&&nums[j]<nums[i]+n)++j;
           len = min(len,n-j+i);
        }
        return len;
    }
};