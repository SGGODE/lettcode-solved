class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k>=n)return *max_element(arr.begin(),arr.end());
        deque<int>pq;
        for(auto&it:arr)pq.push_back(it);
        map<int,int>mp;
        while(1){
            int val = pq.front();pq.pop_front();
            int nxt = pq.front();pq.pop_front();
            if(val>nxt){
                mp[val]++;
                pq.push_front(val);
                pq.push_back(nxt);
            }else{
                mp[nxt]++;
                pq.push_front(nxt);
                pq.push_back(val);
            }
            if(mp[val]==k)return val;
            if(mp[nxt]==k)return nxt;
        }
        return -1;
    }
};