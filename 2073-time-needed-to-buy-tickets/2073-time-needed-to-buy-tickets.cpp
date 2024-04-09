class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>pq;
        for(int i=0;i<tickets.size();i++){
            pq.push({tickets[i],i});
        }
        int time = 0;
        while(!pq.empty()){
            int val = pq.front().first;
            int index = pq.front().second;
            pq.pop();
            if(val==1&&index==k)return time+1;
            if(val>1){
                pq.push({val-1,index});
            }
            time++;
        }
        return time;
    }
};