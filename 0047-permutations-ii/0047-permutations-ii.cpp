class Solution {
private:
    void sub(vector<int>&nums,int index,set<vector<int>>&res){
        if(index>=nums.size()-1){
            //cout<<1<<endl;
            res.insert(nums);
            return;
        }
        for(int i=index+1;i<nums.size();i++){
            swap(nums[index],nums[i]);
            sub(nums,index+1,res);
            swap(nums[index],nums[i]);
            sub(nums,index+1,res);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>res;
        vector<vector<int>>result;
        sub(nums,0,res);
        for(auto&it:res){
            vector<int>temp(it.begin(),it.end());
            result.push_back(temp);
        }
        return result;
    }
};