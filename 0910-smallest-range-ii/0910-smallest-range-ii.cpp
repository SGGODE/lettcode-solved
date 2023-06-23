class Solution {
private:
    int sub(vector<vector<int>>&dp,vector<int>&nums,vector<int>res,int index,int n,int k){
        if(index==n){
            int mi=*min_element(res.begin(),res.end());
            int m=*max_element(res.begin(),res.end());
            return m-mi;
        }
        if(dp[index][abs(nums[index]-res[index])]!=-1)return dp[index][abs(nums[index]-res[index])];
        int minimize=1e9;
        int maximize=1e9;
        if((res[index]-k)>=0){
            res[index]=res[index]-k;
            minimize=sub(dp,nums,res,index+1,n,k);
            res[index]=res[index]+k;
        }
        res[index]+=k;
        maximize=sub(dp,nums,res,index+1,n,k);
        return dp[index][abs(nums[index]-res[index])]=min(minimize,maximize);
    }
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n=nums.size();
        // vector<int>res(nums);
        sort(nums.begin(),nums.end());
        // int m=*max_element(nums.begin(),nums.end());
        // vector<vector<int>>dp(n,vector<int>(k+1,-1));
        // return sub(dp,nums,res,0,n,k);
        int res=nums[n-1]-nums[0];
        for(int i=0;i<n-1;i++){
            int j=i+1;
            int low=min(nums[0]+k,nums[j]-k);
            int high=max(nums[n-1]-k,nums[i]+k);
            res=min(res,high-low);
        }
        return res;
    }
};