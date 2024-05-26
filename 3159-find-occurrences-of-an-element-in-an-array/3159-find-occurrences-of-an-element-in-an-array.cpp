class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int>dp;
        int cnt = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                dp[cnt]=i;
                ++cnt;
            }
        }
        vector<int>result;
        for(auto&it:queries){
            if(dp.count(it))result.push_back(dp[it]);
            else result.push_back(-1);
        }
        return result;
    }
};