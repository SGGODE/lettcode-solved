class Solution {
private:
    int n,m;
    bool check(int row,int col){
        return row>=0&&col>=0&&row<n&&col<m;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&nums) {
        n = nums.size();
        m = nums[0].size();
        map<pair<int,int>,set<int>>mp;
        queue<pair<pair<int,int>,int>>pq;
        for(int i=0;i<n;i++){
            mp[{i,0}].insert(0);
            pq.push({{i,0},0});
        }
        for(int i=0;i<m;i++){
            mp[{0,i}].insert(0);
             pq.push({{0,i},0});
        }
        for(int i=0;i<n;i++){
            mp[{i,m-1}].insert(1);
             pq.push({{i,m-1},1});
        }
        for(int i=0;i<m;i++){
            mp[{n-1,i}].insert(1);
            pq.push({{n-1,i},1});
        }
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        while(!pq.empty()){
            int row = pq.front().first.first;
            int col = pq.front().first.second;
            int val = pq.front().second;
            pq.pop();
            for(int i=0;i<4;i++){
                if(check(row+dx[i],col+dy[i])&&nums[row][col]<=nums[row+dx[i]][col+dy[i]]&&mp[{row+dx[i],col+dy[i]}].find(val)==mp[{row+dx[i],col+dy[i]}].end()){
                    mp[{row+dx[i],col+dy[i]}].insert(val);
                    pq.push({{row+dx[i],col+dy[i]},val});
                }
            }
        }
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp[{i,j}].size()>1)result.push_back({i,j});
            }
        }
        return result;
    }
};