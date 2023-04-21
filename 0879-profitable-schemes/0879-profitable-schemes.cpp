class Solution {
private:
    // int find(vector<int>&group,vector<int>&profit,int n,int sum,int index,vector<vector<bool>>&dp){
    //     if(n>=0&&sum<=0)return 1;
    //     if(sum<=0)return 1;
    //     if(index==0)return (sum<=profit[0])&&(n>=group[0]);
    //     if(dp[index][sum]!=-1)return dp[index][sum];
    //     bool nottake=find(group,profit,n,sum,index-1,dp);
    //     bool take=0;
    //     if(sum<=profit[index]&&n>=group[index]){
    //         take=find(group,profit,n-group[index],sum-profit[index],index-1,dp);
    //     }
    //     return dp[index][sum]=nottake||take;
    // }
    int mod=1e9+7; 
    vector<vector<vector<int>>> memo;
    int find(int n,int p,int index,vector<int>&group,vector<int>&profit){
        if(n<0){
           return 0;
        }
        if(index==group.size()){
            if(p>0)return 0;
            return 1;
        }
        if(memo[index][p][n]!=-1)return memo[index][p][n];
        int take=find(n-group[index],max(0,p-profit[index]),index+1,group,profit);
        int nottake=find(n,p,index+1,group,profit);
        return memo[index][p][n]=(take+nottake)%mod;
    }
public:
    int profitableSchemes(int n, int sum, vector<int>& group, vector<int>& profit) {
         int m=group.size();
         memo = vector<vector<vector<int>>>(m, vector<vector<int>>(sum + 1, vector<int>(n + 1, -1)));
        return find(n,sum,0,group,profit);
        // for(int i=0;i<n;i++){
        //     for(int j=)
        // }
        // return dp[n-1][sum][m-1];
    }
};