class Solution {
private:
    bool check(vector<int>&nums,int val){
        int cnt = 0;
        for(auto&it:nums){
            if(it>=val)++cnt;
        }
        return cnt==val;
    }
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=n;i>=0;i--){
            if(check(nums,i)){
                return i;
            }
        }
        return -1;
    }
};