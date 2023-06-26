class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,-1);
        for(int i=0;i<n;i++){
            bool flag=0;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    res[i]=nums[j];
                    flag=1;break;
                }
            }
            if(!flag){
                for(int j=0;j<i;j++){             
                    if(nums[j]>nums[i]){
                    res[i]=nums[j];
                    flag=1;break;
                }
                }
            }
        }
        return res;
    }
};