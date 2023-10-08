class Solution {
private:
    int dp[501][501][2];
    int sub(vector<int>&nums,vector<int>&nums1,int index1,int index2,bool flag){
        if(index1==nums.size()&&index2==nums1.size())return 0;
        if((index1==nums.size()||index2==nums1.size())&&flag)return 0;
        if((index1==nums.size()||index2==nums1.size())&&!flag)return -1e9;
        if(dp[index1][index2][flag]!=-1)return dp[index1][index2][flag];
        int ans = INT_MIN;
        if(index1<nums.size()&&index2<nums1.size()){
            ans = max(ans,max(nums[index1]*nums1[index2]+sub(nums,nums1,index1+1,index2+1,1),
                              max(ans,max(sub(nums,nums1,index1+1,index2,flag),sub(nums,nums1,index1,index2+1,flag)))));
        }//else{
        //}
        return dp[index1][index2][flag]=ans;
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return sub(nums1,nums2,0,0,0);
    }
};