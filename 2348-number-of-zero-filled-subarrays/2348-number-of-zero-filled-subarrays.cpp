class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
       long long int total=0;
       long long int zero=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                total+=(zero*(zero+1))/2;
                zero=0;
            }else{
                zero++;
            }
        }
        if(zero!=0){
            total+=(zero*(zero+1))/2;
        }
        return total;
    }
};