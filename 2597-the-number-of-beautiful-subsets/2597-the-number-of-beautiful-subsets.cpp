class Solution {
private:
    int sub(vector<int>&nums,int arr[],int index,int k,int subset){
        if(index==nums.size())return subset;
        int ans = 0;
        ans += sub(nums,arr,index+1,k,subset);
        if(nums[index]<=k||(nums[index]>k&&arr[nums[index]-k]==0)){
            arr[nums[index]]++;
            ans += sub(nums,arr,index+1,k,subset or 1);
            arr[nums[index]]--;
        }
        return ans;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int arr[1001]={0};
        int subset = 0;
        return sub(nums,arr,0,k,subset);
    }
};