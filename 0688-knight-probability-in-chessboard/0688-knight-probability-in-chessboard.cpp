class Solution {
private:
    bool check(int row,int col,int n){
        return row>=0&&col>=0&&col<n&&row<n;
    }
    double sub( vector<vector<vector<double>>>&dp,int row,int col,int n,int k){
      if(!check(row,col,n))return 0;
      if(k==0)return 1;
      int dx[8]={-1,1,-2,2,-2,-1,1,2};
      int dy[8]={2,2,1,1,-1,-2,-2,-1};
      double ans=0;
      if(dp[row][col][k]!=-1)return dp[row][col][k];
      for(int i=0;i<8;i++){
          ans+=sub(dp,row+dx[i],col+dy[i],n,k-1)/8.0;
      }
      return dp[row][col][k]=ans;
    }
public:
    double knightProbability(int n, int k, int row, int col) {
     //  if(k==1)return 0;
       //if(n==1&&k==0)return 1
       // queue<pair<pair<int,int>,pair<double,double>>>pq;
       // pq.push({{row,col},{k,1}});
       // double cnt = 0;
       // double denmo = 0;
       // int dx[8]={-1,1,-2,2,-2,-1,1,2};
       // int dy[8]={2,2,1,1,-1,-2,-2,-1};
       // while(!pq.empty()){
       //     int crow=pq.front().first.first;
       //     int ccol=pq.front().first.second;
       //     double rem=pq.front().second.first;
       //     double demo=pq.front().second.second;
       //     pq.pop();
       //     if(rem==0){
       //         ++cnt;
       //         denmo=demo;
       //         continue;
       //     }
       //     for(int i=0;i<8;i++){
       //         if(check(crow+dx[i],ccol+dy[i],n)){
       //             pq.push({{crow+dx[i],ccol+dy[i]},{rem-1,demo*8}});
       //         }
       //     }
       // }
       //  if(cnt==0)return 0;
       // // cout<<cnt<<" "<<denmo<<endl;
       //  return cnt/denmo
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        double res = sub(dp,row,col,n,k);
        return res;
    }
};