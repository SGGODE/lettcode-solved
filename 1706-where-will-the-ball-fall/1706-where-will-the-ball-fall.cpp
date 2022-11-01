class Solution {
//private:
//     bool check(int i,int j,int n,int m){
//   if(i>=0&&j>=0&&j<m&&i<n){
//     return 1;
//   }
//   return 0;
// }
//     void dfs(vector<vector<int>>&v,vector<vector<int>>&vis,int i,int j,vector<int>&x,int n,int m){
// //  if()
//   if(vis[i][j]==1){
//     x.push_back(-1);
//     return;
//   }
//   if(i==n-1&&v[i][j]==-1){
//     x.push_back(j-1);
//     return;
//   }
//    if(i==n-1&&v[i][j]==1){
//     x.push_back(j+1);
//     return;
//   }
//   vis[i][j]=1;
//    if(check(i,j,n,m)&&j==m-1&&v[i][j]==1){
//     x.push_back(-1);
//     return;
//    }
//    if(check(i,j,n,m)&&i==0&&v[i][j]==-1){
//     x.push_back(-1);
//     return;
//    }
  
//   if(check(i,j,n,m)&&check(i+1,j+1,n,m)&&v[i][j]==1&&v[i][j+1]==1){
//     dfs(v,vis,i+1,j+1,x,n,m);
//   }if(v[i][j]==1&&v[i][j+1]==-1){
//     x.push_back(-1);
//     return;
//   }
//   if(check(i,j,n,m)&&check(i+1,j-1,n,m)&&v[i][j]==-1&&v[i][j-1]==-1){
//     dfs(v,vis,i+1,j-1,x,n,m);
//   }if(v[i][j]==-1&&v[i][j-1]==1){
//     x.push_back(-1);
//     return;
//   }
// }
    
// public:
//      vector<int>x;
//   void dfs(vector<vector<int>>&v,int i,int j){
// //  if()
//   int n=v.size();int m=v[0].size();
//   if(i>=n){
//    x.push_back(j);return;
//   }
//   //vis[i][j]=1;

//   if(v[i][j]==1&&v[i][j+1]==1&&j+1<m){
//     dfs(v,i+1,j+1);
//   }
//   else if(v[i][j]==-1&&v[i][j-1]==-1&&j-1>=0){
//     dfs(v,i+1,j-1);
//   }else if(v[i][j-1]==1&&j>=m){
//     x.push_back(-1);return;
//   }else{
//     x.push_back(-1);return;
//   } //return -1;
// }
//     vector<int> findBall(vector<vector<int>>& v) {
//         int n=v.size();int m=v[0].size();
//         if(m==1){
//             return {-1};
//         }
//      //vector<vector<int>>vis(n,vector<int>(m,0));
//     // vector<int>x(m);
//      for(int i=0;i<m;i++){
//        //vector<vector<int>>vis(n,vector<int>(m,0)); dfs(v,vis,0,i,x,n,m);
//        dfs(v,0,i);
//      }
//      return x;
   // }
    public:
    int solve(int i, int j, vector<vector<int>>& grid, int m, int n){

        // base condition: if ball passed all rows then, 
        // ball is out at jth column
        if(i == m) return j;
        
        
        /* At a time a ball can move only left or right, not both
		    so even though we have two choices, only one choise can be executed,
			so the recursive structure is not exponential but rather linear -> O(M)*/
        
        // ball can move right if current board and next board are towards right
        if(grid[i][j] == 1 && j + 1 < n && grid[i][j + 1] == 1){
            return solve(i + 1, j + 1, grid, m, n);
        }
        
        // ball can move left if current board and previous board is towards left
        if(grid[i][j] == -1 && j - 1 >= 0 && grid[i][j - 1] == -1){
            return solve(i + 1, j - 1, grid, m, n);
        }
        
        // if ball couldn't move left or right, then its trapped
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // stores the answer 
        vector<int> fall(n);
        
		// Find the status of each ball -> O(N)
        for(int i = 0; i < n; i++){
            fall[i] = solve(0, i, grid, m, n);
        }
        
        return fall;
    }
};