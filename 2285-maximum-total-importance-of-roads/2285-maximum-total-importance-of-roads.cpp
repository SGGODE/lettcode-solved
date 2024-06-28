class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int>connect;
        for(auto&it:roads){
            connect[it[0]]++;
            connect[it[1]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto&it:connect){
            pq.push({it.second,it.first});
        }
        vector<int>optimalVal(n);
        while(!pq.empty()){
            optimalVal[pq.top().second]=n;
            pq.pop();
            --n;
        }
        long long sum = 0;
        for(auto&it:roads){
            sum += (optimalVal[it[0]]+optimalVal[it[1]]);
        }
        return sum;
    }
};