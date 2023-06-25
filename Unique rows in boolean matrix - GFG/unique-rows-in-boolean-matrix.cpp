//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        //Your code here
        set<pair<int,vector<int>>>res;
       map<vector<int>,int>mp;
        int cnt=0;
        for(int i=0;i<row;i++){
            vector<int>temp;
            for(int j=0;j<col;j++)temp.push_back(M[i][j]);
           res.insert({cnt,temp});
           //mp[temp]++;
            ++cnt;
        }
        vector<vector<int>>result;
       // map<int,int>mp;
        for(auto&it:res){
           if(mp.count(it.second))continue;
           result.push_back(it.second);
           mp[it.second]++;
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends