class Solution {
private:
    long long reverse(int x){
        long long ans = 0;
        while(x!=0){
            int last = x%10;
            ans = ans*10+last;
            x/=10;
        }
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int cnt = 0;
        int mod = 1e9+7;
        map<long long int,int>mp;
        for(auto&it:nums){
            int rev = reverse(it);
            int val = it-rev;
            if(mp.count(val))cnt=(cnt+mp[val])%mod;
            mp[val]++;
        }
        return cnt;
    }
};