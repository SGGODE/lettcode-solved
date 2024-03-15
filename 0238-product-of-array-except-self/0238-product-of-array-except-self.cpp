class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix,suffix;
        int pre = nums[0];
        prefix.push_back(1);
        for(int i=1;i<nums.size();i++){
            prefix.push_back(pre);
            pre*=nums[i];
        }
        int suf = nums[n-1];
        suffix.push_back(1);
        for(int i=n-2;i>=0;i--){
            suffix.push_back(suf);
            suf*=nums[i];
        }
        reverse(suffix.begin(),suffix.end());
        vector<int>result;
        for(int i=0;i<n;i++){
            result.push_back(prefix[i]*suffix[i]);
        }
        return result;
    }
};