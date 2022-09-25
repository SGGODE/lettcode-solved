class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_set<int>s(nums.begin(),nums.end());
        if(s.find(target)==s.end()){
            return -1;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
};