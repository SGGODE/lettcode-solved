class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        for(auto&it:nums)mp[it]++;
        for(int i=0;i<nums.size();i++){
            int s = i+1,e=nums.size()-1;
                while(s<e){
                 //   int mid = (s+e)/2;
                    if((nums[i]+nums[s]+nums[e])==0){
                        st.insert({nums[i],nums[s],nums[e]});
                        s++;
                        e--;
                    }
                    if((nums[i]+nums[s]+nums[e])>0){
                        e -= 1;
                    }else if((nums[i]+nums[s]+nums[e])<0){
                        s += 1;
                    }
                }
        }
        vector<vector<int>>result;
        for(auto&it:st){
            result.push_back(it);
        }
        return result;
    }
};