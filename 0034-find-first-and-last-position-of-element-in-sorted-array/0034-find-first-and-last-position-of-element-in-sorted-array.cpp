class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                v.push_back(i);
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==target){
                v.push_back(i);
                break;
            }
        }
       if(v.empty()){
           return {-1,-1};
       }  
    return v;
    }
};