class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = 1e9;
        int largest = 0;
        int maxDistance = 0;
        priority_queue<pair<int,int>>pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>px;
        for(int i = 0 ; i < arrays.size() ; i++){
            int m = arrays[i].size();
            pq.push({arrays[i][m-1],i});
            px.push({arrays[i][0],i});
        }
        if(pq.top().second == px.top().second){
            int val = pq.top().first;
            pq.pop();
            int val1 = px.top().first;
            px.pop();
            maxDistance = max(maxDistance , val - px.top().first);
            maxDistance = max(maxDistance , pq.top().first - val1);
        }else{
            maxDistance = max(maxDistance , pq.top().first - px.top().first);
        }
        return maxDistance;
    }
};