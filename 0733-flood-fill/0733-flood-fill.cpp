class Solution {
 private:
    int n,m;
    bool check(int i,int j){
        return i>=0&&j>=0&&i<n&&j<m;
    }
//     void fill(vector<vector<int>>& image,vector<vector<int>>&vis,int src,int des,int color,int gotcol){
       
//     }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
       n=image.size();
       m=image[0].size();
       queue<pair<pair<int,int>,int>>pq;
       pq.push({{sr,sc},color});
       vector<vector<bool>>vis(n,vector<bool>(m,0));
       int the_color=image[sr][sc];
        if(color==the_color)return image;
       while(!pq.empty()){
           int row=pq.front().first.first;
           int col=pq.front().first.second;
           image[row][col]=color;
           int paint=pq.front().second;
           vis[row][col]=1;
           pq.pop();
           vector<int>dx{-1,0,1,0};
            vector<int>dy{0,1,0,-1};
           for(int i=0;i<4;i++){
               if(check(row+dx[i],col+dy[i])&&image[row+dx[i]][col+dy[i]]==the_color){
                   image[row+dx[i]][col+dy[i]]=paint;
                   //vis[row+dx[i]][col+dy[i]]=1;
                   pq.push({{row+dx[i],col+dy[i]},paint});
               }
           }
       }
        return image;
    }
};