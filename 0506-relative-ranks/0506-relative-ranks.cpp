class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        vector<string>result(score.size());
        int cnt = 1;
        while(!pq.empty()){
            if(cnt==1)result[pq.top().second]="Gold Medal";
            else if(cnt==2)result[pq.top().second]="Silver Medal";
            else if(cnt==3)result[pq.top().second]="Bronze Medal";
            else{
                result[pq.top().second]=to_string(cnt);
            }
            ++cnt;
            pq.pop();
        }
        return result;
    }
};