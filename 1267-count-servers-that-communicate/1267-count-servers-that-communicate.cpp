class Solution {
private:
    void adjupdate(vector<vector<int>>&grid,int row,int col,vector<int>adj[]){
        int m = grid[0].size();
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]==1){
                adj[(row*m)+col].push_back((i*m)+col);
                break;
            }
        }
        for(int i=row+1;i<grid.size();i++){
            if(grid[i][col]==1){
                adj[(row*m)+col].push_back((i*m)+col);
                break;
            }
        }
         for(int i=col-1;i>=0;i--){
            if(grid[row][i]==1){
                adj[(row*m)+col].push_back((row*m)+i);
                break;
            }
        }
        for(int i=col+1;i<grid[0].size();i++){
            if(grid[row][i]==1){
                adj[(row*m)+col].push_back((row*m)+i);
                break;
            }
        }
    }
    void dfs(vector<int>adj[],vector<bool>&vis,int src,int&cnt){
        vis[src]=1;
        ++cnt;
        for(auto&it:adj[src]){
            if(!vis[it]){
                dfs(adj,vis,it,cnt);
            }
        }
    }
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>adj[(n*m)+1];
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    adjupdate(grid,i,j,adj);
                }
            }
        }
        // for(auto&it:adj){
        //     for(auto vt:it)cout<<vt<<" ";
        //     cout<<endl;
        // }
        vector<bool>vis((n*m)+1,0);
        int total = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[(i*m)+j]&&grid[i][j]==1){
                    int cnt=0;
                    dfs(adj,vis,(i*m)+j,cnt);
                    //cout<<cnt<<endl;
                    if(cnt>1)total+=cnt;
                }
            }
        }
        return total;
    }
};