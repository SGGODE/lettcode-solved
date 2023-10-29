class Solution {
private:
    //int dp[100000][2][100001];
    // int sub(vector<vector<vector<int>>>&dp,vector<int>&nums,int index,int k,int flag,int last){
    //     if(index==nums.size()&&flag)return 0;
    //     if(index==nums.size()&&!flag)return -1e9;
    //     // int is = flag==1?1:0;
    //     // int it = abs(index-last)<=k?1:2;
    //     // if(last==-1)it=0;
    //      if(dp[index][last+1][flag]!=-1)return dp[index][last+1][flag];
    //     // int ans = sub(nums,index+1,k,flag,last);
    //     // for(int i=index;i<nums.size()&&(abs(last-i)<=k||last==-1);i++){
    //     //     ans = max(ans,nums[i]+sub(nums,i+1,k,1,i));
    //     // }
    //     int ans = sub(dp,nums,index+1,k,flag,last);
    //     if(last==-1){
    //         ans = max(ans,nums[index]+sub(dp,nums,index+1,k,1,index));
    //     }else if(abs(last-index)<=k&&last!=-1){
    //          ans = max(ans,nums[index]+sub(dp,nums,index+1,k,1,index));
    //     }
    //     return dp[index][last+1][flag]=ans;
    // }
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        //memset(dp,-1,sizeof(dp));
        int n = nums.size();
       // vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(2,-1)));
       // return sub(dp,nums,0,k,0,-1);
         vector<int>dp(n,0);
         int mod = 1e9+7;
        // for(int i=0;i<nums.size();i++){
        //     int val = nums[i];dp[i]=nums[i];
        //     for(int j=i-1;j>=(i-k)&&j>=0;j--){
        //         val=max(val,(dp[i]+dp[j])%mod);
        //     }
        //     dp[i]=val;
        // }
        // return *max_element(dp.begin(),dp.end());
        priority_queue<pair<int,int>>pq;
        int sum = 0;
        int res = nums[0];
        pq.push({nums[0],0});
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=nums[i];
             while(!pq.empty()&&pq.top().second<(i-k))pq.pop();
             if(!pq.empty()){
                sum = (pq.top().first + nums[i])%mod;
                //cout<<pq.top().first<<" "<<nums[i]<<endl;
                //cout<<sum<<" "<<dp[i]<<endl;
             }
            dp[i] = max(dp[i],sum);
            pq.push({dp[i],i});
            cout<<dp[i]<<endl;
        }
       // cout<<endl;
        return *max_element(dp.begin(),dp.end());
    }
};