class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      int n=nums.size();
      vector<int>dp(n,0);
        sort(nums.begin(),nums.end());
        vector<int>hash(n,-1);
        for(int i=0;i<n;i++){
            int curr=-1;
            int index=-1;
            for(int j=i-1;j>=0;j--){
                if(j<curr)break;
                if((nums[i]%nums[j]==0&&dp[j]>curr) or (nums[j]%nums[i]==0&&dp[j]>curr)){
                    curr=dp[j];
                    index=j;
                }
            }
            if(curr==-1){
                dp[i]=1;
            }
            else{
                dp[i]=curr+1;
                hash[i]=index;
            }
        }
      //  for(auto&it:hash)cout<<it<<" ";
        int maxindex=-1,maxlen=-1;
        for(int i=0;i<n;i++){
            if(maxlen<dp[i]){
                maxlen=dp[i];
                maxindex=i;
            }
        }
        if(maxlen==1)return {nums[0]};
        vector<int>res;
        for(int j=maxindex;j>=0;){
            res.push_back(nums[j]);
            if(hash[j]!=-1){j=hash[j];}
           // ++j;
            else break;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};