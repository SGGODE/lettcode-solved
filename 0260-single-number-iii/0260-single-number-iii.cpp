class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            bool flag=1;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(nums[i]==nums[j]){
                    flag=0;
                    break;
                }
            }
            if(flag)res.push_back(nums[i]);
        }
        return res;
    }
};