class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto&it:s)mp[it]++;
        priority_queue<pair<int,char>>pq;
        for(auto&it:mp){
            pq.push({it.second,it.first});
        }
        string result;
        while(!pq.empty()){
            int time = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            for(int i=0;i<time;i++){
                result.push_back(ch);
            }
        }
        return result;
    }
};