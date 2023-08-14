class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int,int>mp;
        for(auto&it:nums)mp[it]++;
        priority_queue<int>pq;
        for(auto&it:mp){
            pq.push(it.first);
        }
        if(pq.size()<3)return pq.top();
        pq.pop();
        pq.pop();
        return pq.top();
    }
};