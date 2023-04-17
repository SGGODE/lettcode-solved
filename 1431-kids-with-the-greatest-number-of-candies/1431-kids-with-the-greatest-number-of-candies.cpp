class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>&nums, int extraCandies) {
        int n=nums.size();
        vector<bool>res(n,0);
        for(int i=0;i<n;i++){
            bool flag=1;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                else{
                    if(nums[j]>nums[i]+extraCandies){
                        flag=0;
                        break;
                    }
                }
            }
            if(flag)res[i]=1;
        }
        return res;
    }
};