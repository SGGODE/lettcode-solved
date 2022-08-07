class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int c=0,n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[j] - nums[i] == diff and nums[k] - nums[j] == diff)
                      c++;
                }
            }
          //  int j=i+1,k=n-1;
           /* while(j<k){
                if(nums[j] - nums[i] == diff and nums[k] - nums[j] == diff)
                    c++;
                if(nums[j] - nums[i] != diff and nums[k] - nums[j] != diff){
                    j++;
                    k--;
                }
                if(nums[j] - nums[i] != diff)
                    j++;
                if(nums[k] - nums[j] != diff)
                   k--;
            }*/
        }
        return c;
    }
};