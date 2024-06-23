class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i = 0; i < n ; i++){
            int j = i;
            while(j < n && ( nums[j] - nums[i]) <= k)j++;
            i = j-1;
            ++count;
        }
        return count;
    }
};