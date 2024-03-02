class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n);
        int s = 0;
        int e = n-1;
        for(int i = n-1;i>=0;i--){
            if(abs(nums[s])>abs(nums[e])){
                result[i]=nums[s]*nums[s];
                s++;
            }else{
                 result[i]=nums[e]*nums[e];
                 e--;
            }
        }
        return result;
    }
};