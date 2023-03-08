//{ Driver Code Starts
// Initial Template for C++

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countNodes(int i) {
        // your code here
        if(i==1)return 1;
        int cnt=1;
        int total=1;
        int levelcount=2;
        while(cnt!=i){
            ++cnt;
           // total+=levelcount;
           if(cnt!=i)
            levelcount*=2;
        }
        return levelcount;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int i;
        cin >> i;
        Solution ob;
        int res = ob.countNodes(i);

        cout << res;
        cout << "\n";
    }
}

// } Driver Code Ends