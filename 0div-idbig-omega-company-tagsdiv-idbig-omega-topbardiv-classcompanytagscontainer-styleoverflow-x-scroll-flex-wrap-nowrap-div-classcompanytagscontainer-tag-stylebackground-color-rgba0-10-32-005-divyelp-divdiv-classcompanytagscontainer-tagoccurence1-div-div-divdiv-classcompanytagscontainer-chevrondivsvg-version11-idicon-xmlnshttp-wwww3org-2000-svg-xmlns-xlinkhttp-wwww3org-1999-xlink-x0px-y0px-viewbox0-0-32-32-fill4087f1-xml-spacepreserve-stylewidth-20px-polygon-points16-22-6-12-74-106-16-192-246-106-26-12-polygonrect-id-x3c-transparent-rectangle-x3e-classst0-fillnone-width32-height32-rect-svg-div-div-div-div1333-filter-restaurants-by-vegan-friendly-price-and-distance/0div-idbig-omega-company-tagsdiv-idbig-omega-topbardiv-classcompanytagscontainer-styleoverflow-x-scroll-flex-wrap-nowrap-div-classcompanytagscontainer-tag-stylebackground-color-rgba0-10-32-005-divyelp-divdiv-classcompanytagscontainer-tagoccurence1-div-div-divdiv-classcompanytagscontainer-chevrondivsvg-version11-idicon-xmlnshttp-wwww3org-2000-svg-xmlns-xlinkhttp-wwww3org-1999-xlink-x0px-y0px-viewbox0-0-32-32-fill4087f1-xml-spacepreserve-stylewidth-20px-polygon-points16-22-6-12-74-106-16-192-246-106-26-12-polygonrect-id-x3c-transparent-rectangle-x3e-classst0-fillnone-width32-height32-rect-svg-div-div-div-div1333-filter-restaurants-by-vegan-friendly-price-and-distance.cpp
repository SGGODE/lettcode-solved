class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& rest, int vegan, int maxP, int maxD) {
        priority_queue<pair<pair<int,int>,int>>pq;
        for(int i=0;i<rest.size();i++){
            pq.push({{rest[i][1],rest[i][0]},i});
        }
        vector<int>res;
        while(!pq.empty()){
            if(((vegan==1&&rest[pq.top().second][2]==1)||(vegan==0))&&rest[pq.top().second][3]<=maxP&&rest[pq.top().second][4]<=maxD){
                res.push_back(rest[pq.top().second][0]);
            }
            pq.pop();
        }
        return res;
    }
};