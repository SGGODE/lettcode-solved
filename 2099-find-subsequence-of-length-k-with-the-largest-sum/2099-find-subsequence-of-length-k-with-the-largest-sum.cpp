class Solution {
private:
//     int sub(vector<vector<int>>&dp,vector<int>&nums,int index,int n,int k){
//         if(index==n-1){
            
//         }
//     }
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // int sum=0;
        // for(auto &it:nums)sum+=it;
         int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(sum+1,0));
        // sub(dp,nums,0,n,k);
        // int maxsum=0;
        // for(int i=0;i<=sum;i++){
        //     if(dp[n-1][i]==1)maxsum=max(maxsum,i);
        // }
        // return maxsum;
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        vector<pair<int,int>>res;
        for(int i=n-k;i<n;i++){
            res.push_back({temp[i].second,temp[i].first});
        }
        sort(res.begin(),res.end());
        vector<int>result;
        for(int i=0;i<res.size();i++){
            result.push_back(res[i].second);
        }
        return result;
    }
};