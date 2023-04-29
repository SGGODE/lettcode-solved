//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        int n=text.size();
        int m=pat.size();
        if(m==1){
            for(int i=0;i<n;i++){
                string x;x.push_back(text[i]);
                if(x==pat)return i;
            }
        }
        for(int i=0;i<n;i++){
            if(text[i]==pat[0]){
                string x;int cnt=0;
                int j=i;
                while(j<n&&cnt<m){
                    x.push_back(text[j]);
                    j++;
                    cnt++;
                }
                if(x==pat)return i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends