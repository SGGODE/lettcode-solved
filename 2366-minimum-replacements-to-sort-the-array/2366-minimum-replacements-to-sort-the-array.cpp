class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long c=0,lar=1e9+7;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<=lar){
                lar=nums[i];
                continue;
            }
            int parts=ceil(nums[i]/(double)lar);
            c+=parts-1;
            lar=nums[i]/parts;
        }
        return c;
    }
};