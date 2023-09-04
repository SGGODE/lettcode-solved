//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n){
       // Your code here
       vector<int>res;
       vector<int>dp(n,-1);
       int last=-1;
       stack<pair<int,int>>s;
       for(int i=0;i<n;i++){
        int cnt=0;
        while(!s.empty()&&s.top().first<=price[i]){
            cnt+=s.top().second;
            s.pop();
        }
        s.push({price[i],cnt+1});
        res.push_back(cnt+1);
       }
       return res;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends