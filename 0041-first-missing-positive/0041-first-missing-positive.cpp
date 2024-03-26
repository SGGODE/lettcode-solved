class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        set<int>mp;
        for(auto&it:nums)mp.insert(it);
        for(int i=1;i<=n;i++){
            if(!mp.count(i))return i;
        }
        return n+1;
    }
};