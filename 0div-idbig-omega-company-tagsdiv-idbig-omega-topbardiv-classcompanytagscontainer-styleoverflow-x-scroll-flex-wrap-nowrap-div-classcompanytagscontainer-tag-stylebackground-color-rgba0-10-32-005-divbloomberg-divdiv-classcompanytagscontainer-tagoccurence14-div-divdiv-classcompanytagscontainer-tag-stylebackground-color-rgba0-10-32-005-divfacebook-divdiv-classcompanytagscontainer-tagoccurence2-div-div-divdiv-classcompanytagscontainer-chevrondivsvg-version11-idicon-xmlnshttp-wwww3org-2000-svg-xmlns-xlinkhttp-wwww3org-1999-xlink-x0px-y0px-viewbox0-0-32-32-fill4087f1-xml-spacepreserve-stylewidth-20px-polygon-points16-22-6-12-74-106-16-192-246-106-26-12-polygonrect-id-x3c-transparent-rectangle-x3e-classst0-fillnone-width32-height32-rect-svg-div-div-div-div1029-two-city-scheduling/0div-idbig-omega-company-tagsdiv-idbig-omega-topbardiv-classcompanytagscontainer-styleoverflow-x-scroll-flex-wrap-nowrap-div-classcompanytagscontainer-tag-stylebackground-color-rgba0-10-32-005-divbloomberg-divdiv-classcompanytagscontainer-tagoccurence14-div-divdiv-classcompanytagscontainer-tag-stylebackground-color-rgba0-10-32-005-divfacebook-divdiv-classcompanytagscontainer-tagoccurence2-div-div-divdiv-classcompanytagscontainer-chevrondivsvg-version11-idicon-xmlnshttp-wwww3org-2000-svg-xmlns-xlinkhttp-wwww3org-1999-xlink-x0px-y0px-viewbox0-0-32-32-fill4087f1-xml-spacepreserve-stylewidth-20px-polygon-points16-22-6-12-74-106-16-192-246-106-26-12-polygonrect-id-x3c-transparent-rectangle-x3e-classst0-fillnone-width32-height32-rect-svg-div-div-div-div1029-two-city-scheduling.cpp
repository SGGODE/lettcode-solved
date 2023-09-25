class Solution {
private:
    int dp[101][51][51];
    int sub(vector<vector<int>>&nums,int index,int turnA,int turnB){
        if(index==nums.size())return 0;
        if(dp[index][turnA][turnB]!=-1)return dp[index][turnA][turnB];
        int ans = 1e9;
        if(turnA!=0){
            ans = min(ans,nums[index][0]+sub(nums,index+1,turnA-1,turnB));
        }
        if(turnB!=0){
            ans = min(ans,nums[index][1]+sub(nums,index+1,turnA,turnB-1));
        }
        return dp[index][turnA][turnB]=ans;
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        memset(dp,-1,sizeof(dp));
        return sub(costs,0,n/2,n/2);
    }
};