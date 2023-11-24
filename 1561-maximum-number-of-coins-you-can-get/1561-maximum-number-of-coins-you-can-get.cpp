class Solution {
public:
    int maxCoins(vector<int>& piles) {
        priority_queue<pair<int,int>>pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>px;
        for(int i=0;i<piles.size();i++){
            pq.push({piles[i],i});
            px.push({piles[i],i});
        }
        int m = piles.size();
        int sum = 0;
        int n = 0;
        while(!pq.empty()&&!px.empty()&&n<m){
            pq.pop();
            sum+=pq.top().first;
            pq.pop();
            px.pop();
            n+=3;
        }
        return sum;
    }
};