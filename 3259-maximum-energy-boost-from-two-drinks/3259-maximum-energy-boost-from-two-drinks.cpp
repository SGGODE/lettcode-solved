class Solution {
private:
    long long dp[100001][4];
    long long sub(vector<int>&a,vector<int>&b,int index,int array){
        if(index==a.size())return 0;
        if(dp[index][array+1]!=-1)return dp[index][array+1];
        long long ans = 0;
        if(array == -1){
            ans = max(ans,a[index]+sub(a,b,index+1,1));
            ans = max(ans,b[index]+sub(a,b,index+1,2));
        }else{
             if(array == 1){
                 ans = max(ans,a[index]+sub(a,b,index+1,array));
                 ans = max(ans,sub(a,b,index+1,2));
             }else{
                 ans = max(ans,b[index]+sub(a,b,index+1,array));
                 ans = max(ans,sub(a,b,index+1,1));
             }
        }
        return dp[index][array+1]=ans;
    }
public:
    long long maxEnergyBoost(vector<int>&A, vector<int>&B) {
        memset(dp,-1,sizeof(dp));
        return sub(A,B,0,-1);
    }
};