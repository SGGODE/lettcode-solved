class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        map<int,int>mp;
        for(auto it:nums)mp[it]++;
        vector<int>result;
        for(auto it=s.begin();it!=s.end();++it){
         //   cout<<*it<<endl;
            int x=mp[*it];
            for(int i=0;i<x;i++)result.push_back(*it);
        }
        return result;
    }
};