//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
  void sub(vector<int>&v,vector<int>&res,vector<vector<int>>&output,int index,int m,int k,int sum){
      if(index==m){
          int xsum=0;
          for(auto it:res)xsum+=it;
          if(xsum==sum&&res.size()==k)output.push_back(res);
          return;
      }
      res.push_back(v[index]);
      sub(v,res,output,index+1,m,k,sum);
      res.pop_back();
      sub(v,res,output,index+1,m,k,sum);
  }
  public:
    vector<vector<int>> combinationSum(int k, int n) {
        // code here
        vector<int>v{1,2,3,4,5,6,7,8,9};
        int m=v.size();
        vector<int>res;
        vector<vector<int>>output;
        sub(v,res,output,0,m,k,n);
        return output;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends