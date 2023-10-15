class Solution {
private:
    map<pair<int,int>,int>dp;
    int mod = 1e9+7;
    int sub(int index,int step,int len){
        if(index==0&&step==0)return 1;
        if(step==0)return 0;
        if(dp.count({index,step}))return dp[{index,step}];
        int stay = sub(index,step-1,len)%mod;
        int right = 0;
        if(index+1<len){
            right = sub(index+1,step-1,len)%mod;
        }
        int left = 0;
        if(index-1>=0){
            left = sub(index-1,step-1,len)%mod;
        }
        return dp[{index,step}]=((stay+left)%mod+right)%mod;
    }
public:
    int numWays(int steps, int arrLen) {
        return sub(0,steps,arrLen);
    }
};