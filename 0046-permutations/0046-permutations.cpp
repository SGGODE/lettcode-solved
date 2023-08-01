class Solution {
private:
    void sub(vector<vector<int>>&res,vector<int>&nums,int index){
        if(index>=nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
           swap(nums[index],nums[i]);
           sub(res,nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        unordered_map<int,int>mp;
        int n = nums.size();
        sub(res,nums,0);
        return res;
    }
};