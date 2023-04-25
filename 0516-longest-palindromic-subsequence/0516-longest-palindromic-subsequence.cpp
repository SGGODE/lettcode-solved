class Solution {
private:
    bool palindrome(string s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])return 0;
        }
        return 1;
    }
    void sub(string s,string x,int index,int n,int&size){
        if(index==n){
            if(palindrome(x)){
                int t_size=x.size();
                size=max(size,t_size);
            }
            return;
        }
        x.push_back(s[index]);
        sub(s,x,index+1,n,size);
        x.pop_back();
        sub(s,x,index+1,n,size);
    }
public:
    int longestPalindromeSubseq(string s) {
        int maxsize=INT_MIN;
        int n=s.size();
        string s1=s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s1[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        //sub(s,"",0,n,maxsize);
        //return maxsize;
    }
};