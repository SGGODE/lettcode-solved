class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        int totalsum=0;
        for(auto&it:s1)totalsum+=it;
        for(auto&it:s2)totalsum+=it;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=s1[i-1]+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
     //    set<string>res;
     // queue<pair<pair<int,int>,string>>pq;
     // pq.push({{n,m},""});
     // while(!pq.empty()){
     // int row=pq.front().first.first;
     // int col=pq.front().first.second;
     // string x=pq.front().second;
     // pq.pop();
     // if(row<=0||col<=0){
     // reverse(x.begin(),x.end());
     // res.insert(x);
     // continue;
     // }
     // if(s1[row-1]==s2[col-1]){
     // x.push_back(s1[row-1]);
     //                pq.push({{row-1,col-1},x});
     // }else{
     // if(dp[row][col]==dp[row-1][col]){
     // pq.push({{row-1,col},x});
     // }
     // if(dp[row][col]==dp[row][col-1]){
     // pq.push({{row,col-1},x});
     // }
     // }
     // }
     // //   cout<<"total "<<totalsum<<endl;
     //    int sum=INT_MIN;
     //   for(auto&it:res){
     //      int curr=0;
     //      for(auto&vt:it)curr+=int(vt);
     //       sum=max(sum,2*curr);
     //   }
     //   //  string res;
     //   //  int row=n,col=m;
     //   //  while(row>0&&col>m){
     //   //      if(s1[row-1]==s2[col-1]){
     //   //          res.push_back(s1[row-1]);
     //   //          row--;col--;
     //   //          continue;
     //   //      }else if(dp[row-1][col]==dp[row][col-1]){
     //   //          if(int(s1[row-1])>int(s2[col-1])){
     //   //              row--;
     //   //          }else{
     //   //              col--;
     //   //          }
     //   //          continue;
     //   //      }else if(dp[row-1][col]>dp[row][col-1]){
     //   //          row--;
     //   //      }else{
     //   //          col--;
     //   //      } 
     //   //  }
     //   //  int sum=INT_MIN;int curr=0;
     //   // for(auto&it:res){
     //   //    curr+=int(it);
     //   // }
     //   //   sum=max(sum,2*curr);
        return totalsum-(2*dp[n][m]);
    }
};