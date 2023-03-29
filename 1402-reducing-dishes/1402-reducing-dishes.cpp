class Solution {
private:
    void sub(vector<int>&v,vector<int>&res,int&maxsum,int n,int index){
       if(index==n){
           int currsum=0;
           for(int i=0;i<res.size();i++){
               currsum+=(res[i]*(i+1));
           }
           maxsum=max(maxsum,currsum);
           return;
       } 
        res.push_back(v[index]);
        sub(v,res,maxsum,n,index+1);
        res.pop_back();
        sub(v,res,maxsum,n,index+1);
    }
    int solve(vector<int>&v,int index,int time,vector<vector<int>>&dp){
        if(index==v.size())return 0;
        if(dp[index][time]!=-1)return dp[index][time];
        int take=v[index]*(time+1)+solve(v,index+1,time+1,dp);
        int no=solve(v,index+1,time,dp);
        return dp[index][time]=max(take,no);
    }
public:
    int maxSatisfaction(vector<int>& v) {
       sort(v.begin(),v.end());  
      // int n=v.size();
      // int maxsum=INT_MIN;
      // vector<int>res;
      // sub(v,res,maxsum,n,0);
      // return maxsum;
        int n=v.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(v,0,0,dp);
    }
};