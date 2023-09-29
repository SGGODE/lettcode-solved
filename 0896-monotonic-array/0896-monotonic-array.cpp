class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end()))return true;
        reverse(nums.begin(),nums.end());
        return is_sorted(nums.begin(),nums.end());
    }
};