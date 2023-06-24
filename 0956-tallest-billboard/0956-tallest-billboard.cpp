class Solution {
private:
    bool isSubsetSum(vector<vector<int>>&dp,vector<int>&res,int index,int sum){
        if(sum==0)return 1;
        if(index==0)return sum==res[0];
        if(dp[index][sum]!=-1)return dp[index][sum];
        int notpick=isSubsetSum(dp,res,index-1,sum);
        int pick=0;
        if(sum>=res[index]){
            pick=isSubsetSum(dp,res,index-1,sum-res[index]);
        }
        return dp[index][sum]=(pick||notpick);
    }
    int maxsum=INT_MIN;
    int sub(vector<vector<vector<int>>>&dp,vector<int>&nums,int index,int s1,int s2){
        if(index==nums.size()){
            // int sum=0;
            // if(res.size()>1){
            //     for(auto&it:res)sum+=it;
            //     if(sum%2==0)maxsum=max(maxsum,sum/2);
            // }
            // return;
            if(s1==s2)return s1;
            return 0;
        }
        if(dp[index][s1][s2]!=-1)return dp[index][s1][s2];
        int ans1=sub(dp,nums,index+1,s1,s2);
        int ans2=sub(dp,nums,index+1,s1+nums[index],s2);
        int ans3=sub(dp,nums,index+1,s1,s2+nums[index]);
        return dp[index][s1][s2]=max(ans1,max(ans2,ans3));
    }
public:
   int tallestBillboard(vector<int>&rods) {
//    int n = nums.size();
//        int sum=0;
//        for(auto& it:nums)sum+=it;
// //     if (n == 2) {
// //         return nums[0] == nums[1] ? nums[0] : 0;
// //     }
    
// //     vector<bool> vis(n, false);
// //     int sum = accumulate(nums.begin(), nums.end(), 0); 
    
// //     map<int, int> mp;
// //     for (auto& it : nums) {
// //         mp[it]++;
// //     }
    
// //     vector<int> res(nums);
// //     for (int i = 0; i < n; i++) {
// //         if (sum % 2 == 0) {
// //             int m = res.size();
// //             vector<vector<int>> dp(m, vector<int>((sum / 2) + 1, -1));
// //             if (isSubsetSum(dp, res, m - 1, sum / 2)) { 
// //                 return sum / 2;
// //             } else {
// //                 bool flag = false;
// //                 for (int j = 0; j < n; j++) {
// //                     if (nums[j] % 2 == 0 && !vis[j]) {
// //                         sum -= nums[j];
// //                         --mp[nums[j]];
// //                         vis[j] = true;
// //                         flag = true;
// //                         if (mp[nums[j]] == 0) {
// //                             mp.erase(nums[j]);
// //                         }
// //                         break;
// //                     }
// //                 }
// //                 if (flag == false) {
// //                     return 0;
// //                 }
// //             }
// //         } else {
// //             bool flag = false;
// //             for (int j = 0; j < n; j++) {
// //                 if (nums[j] % 2 == 1 && !vis[j]) {
// //                     sum -= nums[j];
// //                     --mp[nums[j]];
// //                     vis[j] = true;
// //                     flag = true;
// //                     if (mp[nums[j]] == 0) {
// //                         mp.erase(nums[j]);
// //                     }
// //                     break;
// //                 }
// //             }
// //             if (flag == false) {
// //                 return 0;
// //             }
// //         }
        
// //         res.clear();
// //         for (auto& it : mp) {
// //             for (int j = 0; j < it.second; j++) {
// //                 res.push_back(it.first);
// //             }
// //         }
// //     }
//     vector<vector<vector<int>>>dp(n,vector<vector<int>>(sum,vector<int>(sum,-1)));
//     return sub(dp,nums,0,0,0);
       // vector<int>res;
       // sub(nums,res,0);
       // return maxsum==INT_MIN?0:maxsum;
          int sum = 0;
    for (int rod : rods) {
      sum += rod;
    }
    int dp[sum + 1];
    dp[0] = 0;
    for (int i = 1; i <= sum; i++) {
      dp[i] = -1;
    }
    for (int rod : rods) {
      int dpCopy[sum + 1];
      copy(dp, dp + (sum + 1), dpCopy);
      for (int i = 0; i <= sum - rod; i++) {
        if (dpCopy[i] < 0) continue;
        dp[i + rod] = max(dp[i + rod], dpCopy[i]);
        dp[abs(i - rod)] = max(dp[abs(i - rod)], dpCopy[i] + min(i, rod));
      }
    }
    return dp[0];
}

};