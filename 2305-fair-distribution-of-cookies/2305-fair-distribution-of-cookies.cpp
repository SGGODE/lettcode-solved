class Solution {
private:
    int sub(vector<int>&dp,vector<int>&nums,vector<int>res,int index){
        if(index==nums.size()){
            return *max_element(res.begin(),res.end());
        }
     //   if(dp[index]!=-1)return dp[index];
        int ans=INT_MAX;
        for(int i=0;i<res.size();i++){
            res[i]=res[i]+nums[index];
            ans=min(ans,sub(dp,nums,res,index+1));
            res[i]=res[i]-nums[index];
        }
        return ans;
    }
public:
    int distributeCookies(vector<int>&nums, int k) {
        int n=nums.size();
        if(n==k)return *max_element(nums.begin(),nums.end());
       vector<int>res(k,0);
        vector<int>dp(n,-1);
        return sub(dp,nums,res,0);
    }
};