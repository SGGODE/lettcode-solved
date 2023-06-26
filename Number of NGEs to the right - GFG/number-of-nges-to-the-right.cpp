//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> count_NGE(int n, vector<int>&arr, int m, vector<int>&nums){
        //write your code here
       vector<int>res;
       vector<int>dp(n,0);
    //   stack<pair<int,int>>s;
    //   for(int i=n-1;i>=0;i--){
    //       if(s.empty()){
    //           s.push({arr[i],i});
    //       }else{
    //           while(!s.empty()&&s.top().first<arr[i])s.pop();
    //           if(!s.empty()){
    //                 dp[i]=dp[i+1];
    //                 ++dp[i];
    //               //dp[i]+=dp[s.top().second];
    //           }
    //           s.push({arr[i],i});
    //       }
    //       // if(i!=n-1)dp[i]=max(dp[i],dp[i+1]);
    //   }
    //   for(int i=0;i<m;i++)res.push_back(dp[nums[i]]);
        for(int i=0;i<m;i++){
            int cnt=0;
           for(int j=nums[i];j<n;j++){
               if(arr[j]>arr[nums[i]])++cnt;
           } 
           res.push_back(cnt);
        }
       return res;
    }

};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> v1(n);
       for(int i = 0;i<n;i++) cin >> v1[i];
        int q; cin >> q;
        vector<int> v2(q);
        for(int i = 0;i<q;i++) cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends