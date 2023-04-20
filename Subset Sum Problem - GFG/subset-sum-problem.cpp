//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{  
private:
    int cnt=0;
    // bool allsub(vector<int>&arr,int target,int index,int sum,int n){
    //     if(index==n){
    //         if(sum==target)return 1;
    //         return 0;
    //     }
    //     sum+=arr[index];
    //     if(allsub(arr,target,index+1,sum,n))return 1;
    //     sum-=arr[index];
    //     if(allsub(arr,target,index+1,sum,n))return 1;
    //     return 0;
    // }
    bool find(int index,int target,vector<int>&arr,vector<vector<int>>&dp){
        if(target==0)return 1;
        if(index==0)return arr[0]==target;
        if(dp[index][target]!=-1)return dp[index][target]; 
        bool nottake=find(index-1,target,arr,dp);
        bool take=0;
        if(target>=arr[index]){
            take=find(index-1,target-arr[index],arr,dp);
        }
        return dp[index][target]=(take||nottake);
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        // vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
       // return find(n-1,sum,arr,dp);
       vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
       for(int i=0;i<n;i++)dp[i][0]=1;
       dp[0][arr[0]]=1;
       for(int i=1;i<n;i++){
           for(int j=1;j<=sum;j++){
             bool nottake=dp[i-1][j];
             bool take=0;
           if(j>=arr[i]){
             take=dp[i-1][j-arr[i]];
          }
           dp[i][j]=(take||nottake);
           }
       }
       return dp[n-1][sum];
      //  return allsub(arr,sum,0,0,n);
       // return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends