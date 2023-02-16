class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       // int j=0;
        int n=nums.size();
        // for(int i=n-1;i>=0;i--){
        //     if(nums[i]%2==0&&nums[j]%2!=0){
        //         swap(nums[i],nums[j]);
        //         ++j;
        //         continue;
        //     }else{
        //         if(nums[i]%2==0){
        //             while(!(nums[j]%2)&&j<n){
        //                 ++j;
        //             }
        //             swap(nums[i],nums[j]);
        //             ++j;
        //         }
        //     }
        // }
        // return nums;
        int i=0;int j=n-1;
        while(i<j){
            if(nums[i]%2!=0&&nums[j]%2==0){
                swap(nums[i],nums[j]);
                --j;++i;
                continue;
            }else if(nums[i]%2==0){
                ++i;
                continue;
            }else if(nums[j]%2!=0){
                --j;
                continue;
            }
        }
        return nums;
    }
};