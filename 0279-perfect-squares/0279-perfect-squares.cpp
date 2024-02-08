class Solution {
private:
    int dp[10001];
    int sub(vector<int>&list,int n,int index){
        if(n==0)return 0;
        if(index==list.size())return 1e9;
        if(dp[n]!=-1)return dp[n];
        int ans = sub(list,n,index+1);
        if(n>=list[index]){
            ans = min(ans,1+sub(list,n-list[index],index));
        }
        return dp[n]=ans;
    }
public:
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        vector<int>list;
        for(int i=1;i<101;i++){
            if((i*i)<=n)list.push_back(i*i);
            else break;
        }
        return sub(list,n,0);
    }
};