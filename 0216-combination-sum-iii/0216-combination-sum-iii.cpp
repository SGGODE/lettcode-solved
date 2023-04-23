class Solution {
private:
    void fun(vector<int>&nums,vector<vector<int>>&res,vector<int>&curr,int k,int index,int tar){
        if(index==9){
            int sum=0;for(auto it:curr)sum+=it;
            if(sum==tar&&curr.size()==k){
                res.push_back(curr);
            }
            return;
        }
        curr.push_back(nums[index]);
        fun(nums,res,curr,k,index+1,tar);
        curr.pop_back();
        fun(nums,res,curr,k,index+1,tar);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>curr;
        vector<int>nums{1,2,3,4,5,6,7,8,9};
        fun(nums,res,curr,k,0,n);
        return res;
    }
};