class Solution {
private:
void help(vector<int>&nums){
     int ind1=0,ind2=0;
        int n=nums.size();
        if(is_sorted(nums.begin(),nums.end())){
            
        }
        //bool flag1=0,flag2=0;
    int i=0;
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind1=i;
                break;
            }
        }
    if(i<0){
        reverse(nums.begin(),nums.end());
            return;
    }
    else{
        for(int j=n-1;j>=0;j--){
            if(nums[j]>nums[ind1]){
                ind2=j;
                break;
            }
        }
        swap(nums[ind1],nums[ind2]);
        reverse(nums.begin()+ind1+1,nums.end());
        return;
    }
}
public:
    void nextPermutation(vector<int>& nums) {
        help(nums);
    }
};