//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    private:
     int sub(int i1,int i2,string s1,string s2,vector<vector<int>>&dp){
        //  if(i1==0||i2==0){
        //      if(s1[i1]==s2[i2])return 1;
        //      return 0;
        //  }
        if(i1<0||i2<0)return 0;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        // int same=0,notsame=0,notsame2=0;
         if(s1[i1]==s2[i2]){
             return 1+sub(i1-1,i2-1,s1,s2,dp);
         }
        // if(s1[i1]!=s2[i2]){
           return  dp[i1][i2]=0+max(sub(i1-1,i2,s1,s2,dp),sub(i1,i2-1,s1,s2,dp));
         //}
         //return max(same,max(notsame,notsame2));
     }//
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2){
        // your code here
        vector<vector<int>>dp(x,vector<int>(y,-1));
        return sub(x-1,y-1,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends