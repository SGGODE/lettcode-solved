class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int cnt=0;
        long long store=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ++cnt;
            }else{
                store=(long long)store+(long long)((cnt*(cnt+1)/2));
                cnt=0;
            }
        }
        if(cnt!=0)store=(long long)store+(long long)((cnt*(cnt+1)/2));
        return store;
    }
};