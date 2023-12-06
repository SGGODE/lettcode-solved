class Solution {
private:
 int dp[100001];
 int sub(int index,vector<int>&prefix,vector<int>&sufix,int n){
    if(index==n||index==n-1)return 0;
    if(dp[index]!=-1)return dp[index];
    int ans = 0;
    if(index+1<n&&prefix[index]==sufix[index+1])ans += 1 + sub(n,prefix,sufix,n);
    ans += sub(index+1,prefix,sufix,n);
    return dp[index]=ans;
 }
public:
    int numSplits(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        vector<int>prefix(n,0);
        set<char>st;
        for(int i=0;i<n;i++){
          st.insert(s[i]);
          prefix[i]=st.size();
        }
        vector<int>sufix(n,0);
        set<char>stz;
        for(int i=n-1;i>=0;i--){
          stz.insert(s[i]);
          sufix[i]=stz.size();
        }
        //cout<<prefix[n-1]<<endl;
        if(prefix[n-1]==1)return n-1;
        return sub(0,prefix,sufix,n);
    }
};