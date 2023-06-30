//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int k) 
    { 
        // Complete the function
        vector<int>res(n,0);
        int sum=0;
        // for(int i=0;i<n;i++){
        //     sum+=A[i];
        //     res[i]=sum;
        // }
        unordered_map<int,int>mp;
        int cnt=INT_MIN;
        //mp[sum]++;
        for(int i=0;i<n;i++){
           sum+=A[i];
           if(sum==k)cnt=i+1;
           if(mp.count(sum-k)){
               cnt=max(cnt,(i-mp[sum-k]));
           }
           if(mp.find(sum)==mp.end())mp[sum]=i;
        }
        return cnt==INT_MIN?0:cnt;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends