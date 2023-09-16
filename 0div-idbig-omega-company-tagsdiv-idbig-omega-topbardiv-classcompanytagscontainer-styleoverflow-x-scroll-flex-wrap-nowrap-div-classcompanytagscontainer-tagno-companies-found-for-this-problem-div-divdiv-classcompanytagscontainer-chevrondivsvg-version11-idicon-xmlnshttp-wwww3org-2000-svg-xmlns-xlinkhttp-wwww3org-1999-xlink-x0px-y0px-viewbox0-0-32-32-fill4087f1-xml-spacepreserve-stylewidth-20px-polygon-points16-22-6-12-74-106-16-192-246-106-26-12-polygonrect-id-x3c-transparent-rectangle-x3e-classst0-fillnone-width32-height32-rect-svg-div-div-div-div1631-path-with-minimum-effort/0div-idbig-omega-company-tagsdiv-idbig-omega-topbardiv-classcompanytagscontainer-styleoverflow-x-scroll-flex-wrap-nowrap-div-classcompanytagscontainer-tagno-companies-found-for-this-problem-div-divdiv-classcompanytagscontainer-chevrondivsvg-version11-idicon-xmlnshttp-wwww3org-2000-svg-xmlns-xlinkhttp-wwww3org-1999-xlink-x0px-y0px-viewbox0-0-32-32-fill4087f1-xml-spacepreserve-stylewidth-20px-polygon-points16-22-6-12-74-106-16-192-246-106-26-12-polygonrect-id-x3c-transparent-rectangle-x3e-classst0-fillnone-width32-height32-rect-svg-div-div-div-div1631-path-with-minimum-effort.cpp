class Solution {
private:
    int sub(vector<vector<int>>&nums,int row,int col){
        int n = nums.size();
        int m = nums[0].size();
        queue<pair<pair<int,int>,int>>pq;
        pq.push({{row,col},0});
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        int res = INT_MAX;
        vector<vector<int>>vis(n,vector<int>(m,1e9));
       // vis[0][0]=1;
        while(!pq.empty()){
            int crow = pq.front().first.first;
            int ccol = pq.front().first.second;
            int cost = pq.front().second;
            pq.pop();
            if(crow==n-1&&ccol==m-1){
                res=min(res,cost);
            }
            for(int i=0;i<4;i++){
                if(crow+dx[i]>=0&&crow+dx[i]<n&&ccol+dy[i]>=0&&ccol+dy[i]<m&&
                   vis[crow+dx[i]][ccol+dy[i]]>max(cost,abs(nums[crow][ccol]-nums[crow+dx[i]][ccol+dy[i]]))){
                    vis[crow+dx[i]][ccol+dy[i]]=max(cost,abs(nums[crow][ccol]-nums[crow+dx[i]][ccol+dy[i]]));
                    pq.push({{crow+dx[i],ccol+dy[i]},max(cost,abs(nums[crow][ccol]-nums[crow+dx[i]][ccol+dy[i]]))});
                }
            }
        }
        return vis[n-1][m-1];
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int res = sub(heights,0,0);
        return res>=1e9?0:res;
    }
};