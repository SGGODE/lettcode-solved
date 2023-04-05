//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
private:
  bool check(int num,int D){
      int curr=num%10;
      num=num/10;
      if(curr==D)return 0;
      while(num!=0){
          int last=num%10;
          if(last<=curr||last==D)return 0;
          curr+=last;
          num=num/10;
      }
      return 1;
  }
  public:
    vector<int> goodNumbers(int L, int R, int D) {
        // code here
        vector<int>res;
        for(int i=L;i<=R;i++){
            if(check(i,D)){
                res.push_back(i);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, D;
        cin >> L >> R >> D;
        Solution ob;
        vector<int> ans = ob.goodNumbers(L, R, D);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends