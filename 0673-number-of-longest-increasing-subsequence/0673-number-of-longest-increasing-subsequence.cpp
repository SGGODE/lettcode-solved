class Solution {
private:
    map<int,int>mp;
     int res=INT_MIN;
    int sub(vector<vector<int>>&dp,vector<int>&nums,int index,int prev){
        if(index==nums.size())return 0;
        if(dp[index][prev+1]!=-1){
           cout<<dp[index][prev+1]<<endl;
            ++mp[dp[index][prev+1]];
            return dp[index][prev+1];
        }
        int notpick=sub(dp,nums,index+1,prev);
        int pick=0;
        if(prev==-1){
            pick=1+sub(dp,nums,index+1,index);
        }
        else{
            if(nums[index]>nums[prev])pick=1+sub(dp,nums,index+1,index);
        }
        mp[max(notpick,pick)]++;
        res=max(res,max(notpick,pick));
        return dp[index][prev+1]=max(pick,notpick);
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
         int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // sub(dp,nums,0,-1);
        // cout<<res<<endl;
        // return mp[res];
       
      //    vector<int>dp(n,1);
      //   // return sub(dp,nums,0,-1);
      // //   map<int,int>mp;
      //   map<int,int>mp;
      //   int res = INT_MIN;
      //   //mp[1]=n;
      //   for(int i=0;i<n;i++){
      //       bool flag=0;
      //       for(int j=0;j<i;j++){
      //           if(nums[i]>nums[j]){
      //               dp[i]=max(dp[i],dp[j]+1);
      //                mp[dp[i]]++;
      //               flag=1;
      //           }
      //       }
      //       if(!flag)mp[dp[i]]++;
      //       res=max(res,dp[i]);
      //   }
      //   cout<<res<<endl;
      //   return mp[res];
      //   int cnt=0;
      //   int maxsum=0;
      //   //cout<<endl;
      //  // for(auto it:dp)cout<<it<<" ";
      // //  sort(dp.begin(),dp.end());
      //   // for(int i=n-2;i>=0;i--){
      //   //     if(dp[i]==dp[i+1])++cnt;
      //   //     else break;
      //   // }
      //   for(int i=0;i<n;i++){
      //       if(mp[i]>maxsum){
      //           maxsum=mp[i];
      //       }
      //   }
      //   return maxsum==0?n:maxsum;
        vector<int>dp(n,1),cnt(n,1);
        int m=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&&dp[j]+1>dp[i]){
                    cnt[i]=cnt[j];
                    dp[i]=dp[j]+1;
                }
                else if(nums[i]>nums[j]&&dp[j]+1==dp[i]){
                    cnt[i]+=cnt[j];
                }
            }
            m=max(m,dp[i]);
        }   
        int res=0;
        for(int i=0;i<n;i++){
            if(dp[i]==m)res+=cnt[i];
        }
        return res;
    }
};