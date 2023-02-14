//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int i=0,j=0;
        unordered_map<int,int>mp;
        int cnt=INT_MIN;
        for(i=0;i<N;i++){
            mp[fruits[i]]++;
            if(mp.size()>2){
                cnt=max(cnt,i-j);
                while(mp.size()>2&&j<N){
                 --mp[fruits[j]];
                 if(mp[fruits[j]]==0)mp.erase(fruits[j]);
                 ++j;
                }
            }else cnt=max(cnt,(i-j)+1);
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends