class Solution {
public:
#define ll long long
    int longestSquareStreak(vector<int>& nums) {
       ll cnt=INT_MIN;
       int n=nums.size();
        map<ll,ll>mp;
        for(auto it:nums)mp[it]++;
       for(auto it:mp){
           ll curr=it.first*it.first;
           ll cntcum=1;
           while(mp.count(curr)==1){
                curr=curr*curr;
               ++cntcum;
           }
           cnt=max(cnt,cntcum);
        }
        if(cnt==1)return -1;
        return cnt;
    }
};