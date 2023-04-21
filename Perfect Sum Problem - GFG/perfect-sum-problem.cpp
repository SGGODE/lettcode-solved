//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
   private:
  // int cnt=0;
   int mod=1e9+7;
     int sub(int sum,int arr[],int index,vector<vector<int>>&dp){
       //  if(index==n){
      // if(sum==0)return 1;
       if(index==0){
             if(sum==0&&arr[0]==0)return 2;
             if(sum==0||arr[0]==sum)return 1;
             //if(index==0) return (arr[0]==sum);
             return 0;
        }
         if(dp[index][sum]!=-1)return dp[index][sum];
         int np=sub(sum,arr,index-1,dp);
         int p=0;
         if(sum>=arr[index]){
             p=sub(sum-arr[index],arr,index-1,dp);
         }
       return dp[index][sum]=(p+np)%mod;
     }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // if(n==1&&arr[0]==sum)return 1;
        // if(n==1&&arr[0]!=sum)return 0;
         vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        // for(int i=0;i<n;i++)dp[i][0]=1;
        // if(sum>=arr[0])dp[0][arr[0]]=2;
        // for(int i=1;i<n;i++){
        //     for(int j=1;j<=sum;j++){
        //       int np=dp[i-1][j];
        //       int p=0;
        //      if(j>=arr[i]){
        //      p=dp[i-1][j-arr[i]];
        //     }
        //     dp[i][j]=p+np;
        //     }
        // }

       return sub(sum,arr,n-1,dp);
        // for(auto it:dp){
        //     for(auto vt:it)cout<<vt<<" ";
        //     cout<<endl;
        // }
        return (dp[n-1][sum])%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends