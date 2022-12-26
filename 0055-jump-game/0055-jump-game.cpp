class Solution {
private:
    void the_finder(vector<int>&nums,int index,int n,bool& flag){
        if(index>=n-1)flag=1;
        //r(int i=
       // return 0;
    }
    bool check(vector<int>&nums,int n){
       bool flag=1;
       for(int i=0;i<n;i++){
           if(nums[i]==0){
               flag=0;
               break;
           }
       }
        if(flag)return 1;
        else the_finder(nums,0,n,flag);
        if(flag) return 1;
        return 0;
    }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
         if(nums[0]==0)return 0;
        // return check(nums,n);
        int target=n-1;
        vector<bool>dp(n,0);
        for(int i=n-2;i>=0;i--){
           if(nums[i]+i>=target){
               dp[i]=1;
               target=i;
           }
        }
        return dp[0];
    }
};