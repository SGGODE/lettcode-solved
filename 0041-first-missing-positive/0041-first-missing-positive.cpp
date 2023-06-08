class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>mp;
        for(auto &it:nums)mp[it]++;
        int m=*max_element(nums.begin(),nums.end());
        for(int i=1;m>0&&i<=m;i++){
            if(mp.count(i)==0)return i;
        }
        if(m>0)return m+1;
        return 1;
    }
};