class Solution {
private:
    int mod=1e9+7;
    int sub(vector<vector<int>>&dp,vector<int>&nums,int start,int end,int fuel){
         //++dp[start];
        // if(start==end){
        //     return 1;
        // }
        if(fuel<0)return 0;
        int sum=0;
        if(dp[start][fuel]!=-1)return dp[start][fuel];
        if(start==end)sum=1;
        if(dp[start][fuel]!=-1)return dp[start][fuel];
        for(int i=0;i<nums.size();i++){
            if(i==start)continue;
            if(abs(nums[i]-nums[start])<=fuel){
                sum=(sum+(sub(dp,nums,i,end,fuel-abs(nums[i]-nums[start])))%mod)%mod;
            }
        }
        return dp[start][fuel]=sum%mod;
    }
    // void sub(vector<int>&dp,vector<int>&nums,int start,int end,int fuel){
    //      ++dp[start];
    //     if(fuel==0)return;
    //     for(int i=0;i<nums.size();i++){
    //         if(i==start)continue;
    //         if(abs(nums[i]-nums[start])<=fuel){
    //             sub(dp,nums,i,end,fuel-abs(nums[i]-nums[start]));
    //         }
    //     }
    // }
public:
    int countRoutes(vector<int>&nums, int start, int end, int fuel) {
       // queue<pair<int,int>>pq;
       // int cnt=0;
       // int n=nums.size();
       // pq.push({start,fuel});
       // while(!pq.empty()){
       //     int node=pq.front().first;
       //     int remain=pq.front().second;
       //     pq.pop();
       //     if(node==end)++cnt;
       //     for(int i=0;i<n;i++){
       //         if(i==node)continue;
       //         if(abs(nums[i]-nums[node])<=remain){
       //             pq.push({i,remain-abs(nums[i]-nums[node])});
       //         }
       //     }
       // }
       //  return cnt;
        int n=nums.size();
       vector<vector<int>>dp(n+1,vector<int>(fuel+1,-1));
        sub(dp,nums,start,end,fuel);
        for(int i=0;i<=fuel;i++){
            cout<<dp[start][i]<<" ";
        }
       cout<<endl;
        return dp[start][fuel];
       // vector<int>dp(n,0);sub(dp,nums,start,end,fuel);
       // return dp[end];
    }
};