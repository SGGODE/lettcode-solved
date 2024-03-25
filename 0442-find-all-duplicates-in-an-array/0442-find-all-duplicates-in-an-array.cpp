class Solution {
private:
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
      //  cycleSort(nums,n);
        vector<int>res;
        for(int i=0;i<n;i++){
            int ind = abs(nums[i])-1;
            if(nums[ind]<0)res.push_back(abs(ind+1));
            nums[ind]=-nums[ind];
        }
        return res;
    }
};