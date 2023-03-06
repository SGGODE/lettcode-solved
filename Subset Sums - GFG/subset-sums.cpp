//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
 private:
    void sub(vector<int>&arr,vector<int>&v,vector<int>&res,int index,int n){
        if(index==n){
            int sum=0;
            for(auto it:v)sum+=it;
            res.push_back(sum);
            return;
        }
        v.push_back(arr[index]);
        sub(arr,v,res,index+1,n);
        v.pop_back();
        sub(arr,v,res,index+1,n);
    }
public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int>v;
        vector<int>res;
        sub(arr,v,res,0,n);
       // vector<int>output(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends