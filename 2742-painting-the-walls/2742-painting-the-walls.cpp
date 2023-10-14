class Solution {
private:
    int dp[501][501];
    int sub(vector<int>& cost, vector<int>& time,int index,int sum){
        if(sum<=0){
            return 0;
        }
        if(index==cost.size())return 1e9;
        if(dp[index][sum]!=-1)return dp[index][sum];
        long long int notpick = sub(cost,time,index+1,sum);
        long long int pick = INT_MAX;
        if(sum>0){
            pick = cost[index]+sub(cost,time,index+1,sum-(time[index]+1));
        }
        return dp[index][sum]=min(pick,notpick);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(dp,-1,sizeof(dp));
        return sub(cost,time,0,n);
    }
};