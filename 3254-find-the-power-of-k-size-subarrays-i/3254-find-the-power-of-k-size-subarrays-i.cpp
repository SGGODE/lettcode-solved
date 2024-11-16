class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        //brute force O(n*k) time and O(n-k) space.
        int n = nums.size();
        vector<int>result;
        for(int i = 0; i <= (n-k); i++){
            bool redFlaghaiTu = 0;
            for(int j = i+1; j < (i+k); j++){
                if(nums[j] - 1 != nums[j-1])redFlaghaiTu = 1;
            }
            if(redFlaghaiTu)result.push_back(-1);
            else result.push_back(nums[(i+k)-1]);
        }
        return result;
    }
};