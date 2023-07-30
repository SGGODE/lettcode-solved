class Solution {
private:
    int sub(vector<vector<int>>&dp,const string&s,int start,int end){
        if(start==end)return 1;
        if(dp[start][end]!=-1)return dp[start][end];
        int ans=INT_MAX;
        for(int k=start;k<end;k++){
            ans=min(ans,sub(dp,s,start,k)+sub(dp,s,k+1,end));
        }
        return dp[start][end]=(s[start]==s[end])?ans-1:ans;
    }
public:   
int strangePrinter(string s) {
    int n = s.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return sub(dp,s,0,n-1);
}
};