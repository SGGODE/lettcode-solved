class Solution {
private:
  private:
    int sub(vector<vector<int>>&dp,vector<int>&cuts,int start,int end){
        if(start>end)return 0;
        if(dp[start][end]!=-1)return dp[start][end];
        int cost=INT_MAX;
        for(int i=start;i<=end;i++){
            cost=min(cost,(cuts[end+1]-cuts[start-1])+sub(dp,cuts,start,i-1)+sub(dp,cuts,i+1,end));
        }
        return dp[start][end]=cost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
       int m = cuts.size();
        sort(cuts.begin(),cuts.end());
      // vector<bool>vis(m,0);
        cuts.insert(cuts.begin(),0);
        cuts.insert(cuts.end(),n);
       // for(auto&it:cuts)cout<<it<<" ";
       // cout<<endl;
        int x = cuts.size();
        vector<vector<int>>dp(x+1,vector<int>(x+1,-1));
       return sub(dp,cuts,1,m);
    }
};