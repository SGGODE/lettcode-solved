class Solution {
public:
    int search(vector<int>& nums, int target) {
       map<int,int>mp;
       for(int i=0;i<nums.size();i++){
           mp[nums[i]]=i;
       }
       sort(nums.begin(),nums.end());
       int n = nums.size();
       int s = 0;
       int e = n-1;
       while(s<=e){
           int mid = (s+e)/2;
           if(nums[mid]==target)return mp[nums[mid]];
           if(nums[mid]>target){
               e=mid-1;
           }else{
               s=mid+1;
           }
       }
        return -1;
    }
};