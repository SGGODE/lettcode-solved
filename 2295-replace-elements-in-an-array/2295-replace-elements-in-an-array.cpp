class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(auto&it:operations){
           int index = mp[it[0]];
           nums[index] = it[1];
           mp[nums[index]]=index;
        }
       // vector<int>res(s.begin(),s.end());
        return nums;
    }
};