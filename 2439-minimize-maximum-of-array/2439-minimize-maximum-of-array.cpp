class Solution {
private:
    bool check(int mid,vector<int>&nums){
       long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>(long)mid*(i+1))return 0;
        }
        return 1;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int s=0;
        int e=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;
            if(check(mid,nums)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};