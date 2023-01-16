class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       // int oddcnt=0;
       int n=nums.size();
       //  for(int i=0;i<n;i++){
       //      if(nums[i]%2!=0)oddcnt++;
       //  }
       //  int cnt=0;
       //  int oddcnt1=oddcnt;
       //  for(int i=0;i<n;i++){
       //      if(oddcnt>=k)cnt++;
       //      if(nums[i]%2!=0)--oddcnt1;
       //  }
       //  for(int i=n-1;i>=0;i--){
       //      if(oddcnt>=k)cnt++;
       //      if(nums[i]%2!=0)--oddcnt;
       //  }
       //  return cnt;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)nums[i]=0;
            else nums[i]=1;
        }
        int sum=0;
        map<int,int>mp;
        mp[sum]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
           // if(sum==k)++cnt;
            if(mp.find(sum-k)!=mp.end())cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};