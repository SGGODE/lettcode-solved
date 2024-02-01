class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<nums.size()-2;i++){
            int mn = 1e9,mx=0;
            for(int j=i;j<i+3;j++){
                mn=min(mn,nums[j]);
                mx=max(mx,nums[j]);
            }
            if(abs(mn-mx)>k)return {};
            i+=2;
        }
        for(int i=0;i<nums.size()-2;i++){
            vector<int>temp(nums.begin()+i,(nums.begin()+i)+3);
            res.push_back(temp);
            i+=2;
        }
        return res;
    }
};