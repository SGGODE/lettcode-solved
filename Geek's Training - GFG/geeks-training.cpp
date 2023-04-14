//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>res(n,vector<int>(3,0));
        for(int i=0;i<1;i++){
            for(int j=0;j<3;j++){
                res[i][j]=points[i][j];
            }
        }
        for(int i=1;i<n;i++){
          for(int m=0;m<3;m++){
            int maxcnt=INT_MIN;
            for(int j=i-1;j<i;j++){
                for(int k=0;k<3;k++){
                  if(k==m)continue;
                  maxcnt=max(maxcnt,res[j][k]);
                }
            }
            res[i][m]=points[i][m]+maxcnt;
          }
        }
        return *max_element(res[n-1].begin(),res[n-1].end());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends