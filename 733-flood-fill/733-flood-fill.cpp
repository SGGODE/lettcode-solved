class Solution {
private:
    void fill(vector<vector<int>>& image,vector<vector<int>>&vis,int src,int des,int color,int gotcol){
        int n=image.size();
        int m=image[0].size();
        vis[src][des]=1;
        image[src][des]=color;
        int dx[4]={-1,0,+1,0};
        int dy[4]={0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nr=src+dx[i];
            int nc=des+dy[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && image[nr][nc]==gotcol && !vis[nr][nc])
                fill(image,vis,nr,nc,color,gotcol);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> copimg=image;
        int gotcol=image[sr][sc];
        fill(copimg,vis,sr,sc,color,gotcol);
        return copimg;
    }
};