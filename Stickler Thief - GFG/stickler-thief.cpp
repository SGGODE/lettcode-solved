//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n==1)return arr[0];
        vector<int>dp(n,0);
        dp[0]=arr[0];
       // dp[1]=arr[1];
        priority_queue<pair<int,int>>pq;
        pq.push({arr[0],0});
        pq.push({arr[1],1});
        for(int i=1;i<n;i++){
            // int m=INT_MIN; priority_queue<pair<int,int>>px(pq);
            // while(!px.empty()&&px.top().second == i-1){
            //     px.pop();
            // }
            // dp[i]=arr[i]+px.top().first;
            // pq.push({dp[i],i});
            int curr=arr[i];
            if(i>1){
                curr+=dp[i-2];
            }
            int miss=dp[i-1];
            dp[i]=max(curr,miss);
        }
      //  cout<<dp[n-1]<<endl;
        return dp[n-1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends