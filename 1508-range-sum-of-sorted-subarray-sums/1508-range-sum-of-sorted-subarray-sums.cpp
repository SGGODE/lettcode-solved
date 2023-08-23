class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long int>res;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum=(sum+nums[j])%mod;
                res.push_back(sum%mod);
            }
        }
        sort(res.begin(),res.end());
        long long int result=0;
        for(int i=left-1;i<right;i++){
           result=(result+res[i])%mod;
        }
        return result;
    }
};