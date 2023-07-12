class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int s=i+1;
            int e=n-1;
            while(s<e){
                if(nums[i]+nums[s]+nums[e]==0){
                    res.insert({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }
                if(nums[i]+nums[s]+nums[e]>0){
                    e--;
                }
                 if(nums[i]+nums[s]+nums[e]<0){
                    s++;
                }
            }
        }
        vector<vector<int>>result;
        for(auto&it:res){
            vector<int>temp(it.begin(),it.end());
            result.push_back(temp);
        }
        return result;
    }
};