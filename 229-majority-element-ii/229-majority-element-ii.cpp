class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int cnt=n/3;
        set<int>v;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]>cnt){
                v.insert(nums[i]);
            }
        }
        vector<int>x(v.begin(),v.end());
        return x;
    }
};