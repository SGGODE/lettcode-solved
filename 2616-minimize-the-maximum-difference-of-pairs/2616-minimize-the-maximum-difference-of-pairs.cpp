class Solution {
public:
    bool solve(vector<int>&nums, int pairs,int mid){
        int count=0;
        int n=nums.size();
        int i=1;
        while (i<n){
            if(nums[i]-nums[i-1]<=mid){
                count++;
                i=i+2;
            }
            else{
                i=i+1;
            }
            if(count>=pairs){
                return true;
            }
        }
        return false;

    }
    int minimizeMax(vector<int>& nums, int p) {
        // if (p==0){
        //     return 0;
        // }
        sort(nums.begin(), nums.end());
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        int l=0;
        int h=maxi;
        int mid;
        int ans=0;
        while(l<=h){
            mid=(l+h)/2;
            if(solve(nums,p,mid)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
// class Solution {
// private:
//     int sub( vector<vector<vector<int>>>&dp,vector<int>&nums,int index,int p,int last){
//         if(p==0){
//             return 0;
//         }
//         if(index==nums.size())return 1e9;
//         if(dp[index][last+1][p]!=-1)return dp[index][last+1][p];
//         int notpick=sub(dp,nums,index+1,p,last);
//         int pick=0;
//         if(last==-1){
//             pick=sub(dp,nums,index+1,p,index);
//         }else{
//             pick=max(abs(nums[index]-nums[last]),sub(dp,nums,index+1,p-1,-1));
//         }
//         return dp[index][last+1][p]=min(pick,notpick);
//     }
// public:
//     int minimizeMax(vector<int>& nums, int p) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(p+1,-1)));
//         return sub(dp,nums,0,p,-1);
//     }
// };
// class Solution {
// private:
//     int sub( vector<vector<int>>&dp,vector<int>&nums,int index,int p){
//         if(p==0){
//             return 0;
//         }
//         if(index+1>=nums.size())return 1e9;
//         if(dp[index][p]!=-1)return dp[index][p];
//         int notpick=sub(dp,nums,index+1,p);
//         int pick=max(abs(nums[index]-nums[index+1]),sub(dp,nums,index+2,p-1));
//         return dp[index][p]=min(pick,notpick);
//     }
// public:
//     int minimizeMax(vector<int>& nums, int p) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end());
//         vector<vector<int>>dp(n,vector<int>(p+1,-1));
//         return sub(dp,nums,0,p);
//     }
// };