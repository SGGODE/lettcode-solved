//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        //  vector<pair<int,int>>adj[n];
        //  for(auto it:edges){
        //      adj[it[0]].push_back({it[1],it[2]});
        //  }
        //  int number=INT_MAX;
        //  int result=INT_MIN;
        //  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //  for(int i=0;i<n;i++){
        //      if(adj[i].empty())continue;
        //      vector<int>res(n,1e9);
        //      res[i]=0;
        //      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        //      q.push({0,i});
        //      while(!q.empty()){
        //          int node=q.top().second;
        //          int cost=q.top().first;
        //          q.pop();
        //          for(auto it:adj[node]){
        //              if(res[it.first]>cost+it.second){
        //                  res[it.first]=cost+it.second;
        //                  q.push({cost+it.second,it.first});
        //              }
        //          }
        //      }
        //      int cnt=0;
        //      for(int j=0;j<n;j++){
        //          if(j==i)continue;
        //          if(res[j]<=distanceThreshold)++cnt;
        //      }
        //      if(cnt<number){
        //          number=cnt;
        //          result=i;
        //      }else if(cnt==number){
        //          result=max(result,i);
        //      }
        //      pq.push({cnt,i});
        //  }
        // //  int x=pq.top().first;
        // //  vector<int>v;
        // //  while(!pq.empty()){
        // //      if(x==pq.top().first){
        // //          v.push_back(pq.top().second);
        // //      }else break;
        // //      pq.pop();
        // // }
        // //  sort(v.begin(),v.end());
        // //  int r=v.size();
        // //  return v[r-1];
        // return result;
        vector<vector<int>>res(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            res[i][i]=0;
        }
        for(int i=0;i<m;i++){
          res[edges[i][0]][edges[i][1]]=edges[i][2];
          res[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    res[j][k]=min(res[j][k],res[j][i]+res[i][k]);
                }
            }
        }
        int maxcnt=INT_MAX;
        int city=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(res[i][j]<=distanceThreshold)++cnt;
            }
            if(cnt<=maxcnt){
                maxcnt=cnt;
                city=max(city,i);
            }
        }
        return city;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends