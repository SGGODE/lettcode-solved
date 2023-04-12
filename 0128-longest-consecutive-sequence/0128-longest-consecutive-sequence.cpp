class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int cnt=1;
        int longest=INT_MIN;
        int last=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end()){
                int j=nums[i];
                cnt=1;
                while(s.find(j+1)!=s.end()){
                    ++j;
                    ++cnt;
                }
                longest=max(cnt,longest);
            }
        }
        if(longest==INT_MIN)return 0;
        return longest;
    }
};