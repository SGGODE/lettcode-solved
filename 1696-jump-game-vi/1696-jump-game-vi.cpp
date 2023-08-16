class Solution {
private:
    int sub(vector<int>&dp,vector<int>&nums,int index,int k){
        if(index==nums.size()-1)return nums[index];
        if(dp[index]!=-1)return dp[index];
        int ans=-1e9;
        for(int i=index+1;i<=index+k&&i<nums.size();i++){
            ans=max(ans,nums[index]+sub(dp,nums,i,k));
        }
        return dp[index]=ans;
    }
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(nums);
        priority_queue<pair<int,int>>pq;
        pq.push({nums[0],0});
        for(int i=1;i<k&&i<n;i++){
            dp[i]+=pq.top().first;
            pq.push({dp[i],i});
        }
        for(int i=k;i<n;i++){
            while(!(pq.top().second>=(i-k)))pq.pop();
            dp[i]+=pq.top().first;
            pq.push({dp[i],i});
        }
      //  for(auto&it:dp)cout<<it<<" ";
        //cout<<endl;
        return dp[n-1];
        //return sub(dp,nums,0,k);
    }
};