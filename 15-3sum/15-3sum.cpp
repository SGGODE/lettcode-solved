class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>v;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int s=i+1,e=n-1;
            while(s<e){
                if(nums[i]+nums[s]+nums[e]==0){
                    v.insert({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }else if(nums[i]+nums[s]+nums[e]>0){
                    e--;
                }else{
                    s++;
                }
            }
       }vector<vector<int>>x(v.begin(),v.end());
        return x;
    }
};