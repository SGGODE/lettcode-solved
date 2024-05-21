class Solution {
private:
    vector<vector<int>>result;
    void sub(vector<int>&nums,vector<int>&res,int index){
        if(index==nums.size()){
            result.push_back(res);
            return;
        }
        res.push_back(nums[index]);
        sub(nums,res,index+1);
        res.pop_back();
        sub(nums,res,index+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>res;
        sub(nums,res,0);
        return result;
    }
};