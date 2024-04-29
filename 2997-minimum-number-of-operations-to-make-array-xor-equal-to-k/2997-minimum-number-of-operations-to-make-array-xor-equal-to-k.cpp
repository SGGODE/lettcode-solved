class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto&it:nums)sum ^= it;
        int res = 0;
        k ^= sum; 
        while(k>0){
            res+=(k&1);
            k>>=1;
        }
        return res;
    }
};