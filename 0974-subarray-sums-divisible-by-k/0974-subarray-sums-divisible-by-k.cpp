class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       //  vector<int>v;
       //  int sum=0;int cnt=0;
       //  map<int,int>mp;
       //  for(int i=0;i<nums.size();i++){
       //      sum+=nums[i];
       //      if(mp.find(sum%k)!=mp.end())cnt+=mp[sum%k];
       //      mp[sum%k]++;
       //  }
       // // for(auto it:v)cout<<it<<" ";
       //  return cnt;
        map<int,int>mp;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mp[((sum%k)+k)%k]++;
        }
        int cnt=mp[0];
        for(auto it:mp){
            cnt+=(it.second*(it.second-1))/2;
        }
        return cnt;
    }
};