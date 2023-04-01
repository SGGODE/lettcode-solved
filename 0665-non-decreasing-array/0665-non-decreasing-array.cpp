class Solution {
private:
    int decreasing(vector<int>&nums){
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1])return i-1;
        }
        return -1;
    }
public:
    bool checkPossibility(vector<int>& nums) {
       int n=nums.size();
        int i=decreasing(nums);
        if(i==-1)return 1;
        vector<int>one(nums);
        vector<int>second(nums);
        one[i]=one[i+1];
        second[i+1]=second[i];
        if(decreasing(one)==-1)return 1;
        if(decreasing(second)==-1)return 1;
        return 0;
    }
};