class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        map<int,int>mp;
        for(int i=0;i<n;i++){
           mp[nums[i]]++;
        }
        for(auto&it:mp){
            if(it.second==1)res.push_back(it.first);
        }
        return res;
    }
};