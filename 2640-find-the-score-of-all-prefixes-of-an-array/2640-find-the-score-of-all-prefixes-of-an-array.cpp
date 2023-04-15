class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int maxi=INT_MIN;
        long long int sum=0;
        vector<long long>res;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            res.push_back(maxi+sum+nums[i]);
            sum+=maxi+nums[i];
        }
        return res;
    }
};