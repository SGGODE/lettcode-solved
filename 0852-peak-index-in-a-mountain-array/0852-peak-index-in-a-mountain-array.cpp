class Solution {
public:
    int peakIndexInMountainArray(vector<int>&nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<e){
            int mid=(s+e)/2;
            if(mid>=1){
                if(nums[mid-1]<nums[mid]&&nums[mid+1]<nums[mid])return mid;
                else if(nums[mid-1]<nums[mid]&&nums[mid+1]>nums[mid]){
                    s++;
                }else{
                    e--;
                }
            }
        }
        return s;
    }
};