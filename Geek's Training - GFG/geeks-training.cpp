//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
  int dp[100001][4];
  int sub(vector<vector<int>>&points,int last,int index){
      if(index==points.size())return 0;
      if(dp[index][last]!=-1)return dp[index][last];
      int ans = 0;
      if(last==0){
          ans = max(ans,max({points[index][0]+sub(points,1,index+1),points[index][1]+sub(points,2,index+1),
                             points[index][2]+sub(points,3,index+1)}));
      }else if(last==1){
          ans = max(ans,max(points[index][1]+sub(points,2,index+1),
                             points[index][2]+sub(points,3,index+1)));
      }else if(last==2){
          ans = max(ans,max(points[index][0]+sub(points,1,index+1),
                             points[index][2]+sub(points,3,index+1)));
      }else{
          ans = max(ans,max(points[index][1]+sub(points,2,index+1),
                             points[index][0]+sub(points,1,index+1)));
      }
      return dp[index][last]=ans;
  }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return sub(points,0,0);
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