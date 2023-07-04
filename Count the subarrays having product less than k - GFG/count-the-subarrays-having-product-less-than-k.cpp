//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>&nums, int n, long long k) {
        map<int,int>mp;
        int cnt=0;
        for(int i=0;i<n;i++){
           long long int sum=1;
            for(int j=i;j<n;j++){
                if(sum*nums[j]<k){
                    sum*=nums[j];
                    ++cnt;
                }else break;
            }        
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends