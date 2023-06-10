class Solution {
private:
    bool flag=0;
    bool solve(vector<int>&piles,vector<vector<int>>&dp,int start,int end,int alice,int bob,int turn,int s){
        if(end<=start){
            if(turn==0)alice+=piles[end];
            else bob+=piles[end];
            if(alice>bob)return 1;
            return 0;
        }
       if(dp[start][end]!=-1)return dp[start][end];
        bool s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0,s9=0,s10=0,s11=0,s12=0;
        if(piles[start]==piles[end]){
            if(turn==0){
                s1=solve(piles,dp,start+1,end,alice+piles[start],bob,1,1);
                s2=solve(piles,dp,start,end-1,alice+piles[end],bob,1,0);
            }else{
                s3=solve(piles,dp,start+1,end,alice,bob+piles[start],0,1);
                s4=solve(piles,dp,start,end-1,alice,bob+piles[end],0,0);
            }
        }
        if(piles[start]>piles[end]){
             if(turn==0){
                s5=solve(piles,dp,start+1,end,alice+piles[start],bob,1,1);
                s6=solve(piles,dp,start,end-1,alice+piles[end],bob,1,0);
            }else{
                s7=solve(piles,dp,start+1,end,alice,bob+piles[start],0,1);
               s8=solve(piles,dp,start,end-1,alice,bob+piles[end],0,0);
            }
        }else{
             if(turn==0){
                s9=solve(piles,dp,start+1,end,alice+piles[start],bob,1,1);
                s10=solve(piles,dp,start,end-1,alice+piles[end],bob,1,0);
            }else{
                s11=solve(piles,dp,start+1,end,alice,bob+piles[start],0,1);
                s12=solve(piles,dp,start,end-1,alice,bob+piles[end],0,0);
            }
        }
        return dp[start][end]=(s1||s2||s3||s4||s5||s6||s7||s8||s9||s10||s11||s12);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(piles,dp,0,n-1,0,0,0,0);
       // return flag;
    }
};