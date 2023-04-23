//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int sub(vector<int>&arr,int index,int sum,vector<vector<int>>&dp){
      //if(target==sum)return 1;
      if(index==0){
          if(arr[0]==0&&sum==0)return 2;
          return (sum==arr[0]||sum==0);
      }
     // if(dp[index][target]!=-1)return dp[index][target];
      int ptake=sub(arr,index-1,sum,dp);
      int ntake=sub(arr,index-1,sum-arr[index],dp);
      return ptake+ntake;
  }

    int findTargetSumWays(vector<int>&arr ,int target) {
        //Your code here
        int n=arr.size();
        int sum=0;
        for(auto it:arr)sum+=it;
        if(sum-target<0||((sum-target)%2==1))return 0;
        vector<vector<int>>dp(n,vector<int>((((sum-target)/2)+1),-1));
        set<vector<int>>st;vector<int>v;
       return sub(arr,n-1,((sum-target)/2),dp);
       //return cnt;
    //   return st.size();
    //     return dp[n-1][target];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends