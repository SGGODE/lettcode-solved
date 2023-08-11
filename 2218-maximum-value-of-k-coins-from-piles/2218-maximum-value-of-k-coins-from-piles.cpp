class Solution {
private:
    int sub(vector<vector<int>>&dp,vector<vector<int>>& piles,int k,int index){
        if(k==0)return 0;
        if(index==piles.size())return 0;
        if(dp[index][k]!=-1)return dp[index][k];
        int notpick=sub(dp,piles,k,index+1);
        int sum=0;
        int pick=0;
        for(int i=0;i<piles[index].size()&&i<k;i++){
            sum+=piles[index][i];
            pick=max(pick,sum+sub(dp,piles,k-(i+1),index+1));
        }
        return dp[index][k]=max(pick,notpick);
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return sub(dp,piles,k,0);
    }
};