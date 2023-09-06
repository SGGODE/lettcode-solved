class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int>prefixzero,prefixone;
        int one=0;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)++zero;
            else ++one;
            prefixzero.push_back(zero);
            prefixone.push_back(one);
        }
        map<int,vector<int>>res;
        int n = nums.size();
        res[prefixone[n-1]].push_back(0);
        //res[prefixzero[n-1]].push_back(n+1);
        for(int i=0;i<n;i++){
            int divide = 0;
            divide += prefixzero[i];
            divide += prefixone[n-1]-prefixone[i];
            res[divide].push_back(i+1);
        }
        int maxsum = 0;
        for(auto&it:res)maxsum=max(maxsum,it.first);
        return res[maxsum];
    }
};