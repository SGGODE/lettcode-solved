class Solution {
public:
    string frequencySort(string s) {
       map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string v;
        while(!pq.empty()){
            for(int i=0;i<pq.top().first;i++){
             v.push_back(pq.top().second);
            }
            pq.pop();
        }
        return v;
    }
};