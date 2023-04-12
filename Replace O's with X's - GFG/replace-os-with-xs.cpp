//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int ln,lm;
    bool boundary(int row,int col){
        return (row==0||col==0||row==ln-1||col==lm-1);
    }
    bool check(int row,int col){
        return row>=0&&col>=0&&row<ln&&col<lm;
    }
    void dfs(vector<vector<char>>&mat,vector<vector<bool>>&vis,int row,int col){
        vis[row][col]=1;
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        for(int i=0;i<4;i++){
            if(check(row+dx[i],col+dy[i])&&!vis[row+dx[i]][col+dy[i]]&&mat[row+dx[i]][col+dy[i]]=='O'){
                dfs(mat,vis,row+dx[i],col+dy[i]);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        // code here
        ln=n;
        lm=m;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(boundary(i,j)&&mat[i][j]=='O'){
                    dfs(mat,vis,i,j);
                }
            }
        }
        vector<vector<char>>res(n,vector<char>(m,'X'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1&&mat[i][j]=='O'){
                    res[i][j]='O';
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends