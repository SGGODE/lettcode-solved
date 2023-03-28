//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        int odd=0;
        map<int,int>mp;
        int cnt=0;
        mp[odd]=1;
        for(int i=0;i<n;i++){
            if(nums[i]%2)++odd;
            if(mp.count(odd-k)){
                cnt+=mp[odd-k];
            }
            mp[odd]++;
        }
        return cnt; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends