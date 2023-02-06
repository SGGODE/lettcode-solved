class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>result;
        int k=0;
        int j=n;
        for(int i=0;i<2*n;i++){
            if(i%2==0)result.push_back(nums[k++]);
            else result.push_back(nums[j++]);
        }
        return result;
    }
};