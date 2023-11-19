class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(auto&it:nums)mp[it]++;
        set<int>s(nums.begin(),nums.end());
        int one = *min_element(nums.begin(),nums.end());
        if(s.size()==1)return 0;
        priority_queue<pair<pair<int,int>,int>>pq;
        for(auto&it:s){
            pq.push({{it,mp[it]},0});
        }
        while(pq.size()>1){
            int first = pq.top().first.first;
            int freq = pq.top().first.second;
            int ops = pq.top().second;
            pq.pop();
            int sec = pq.top().first.first;
            int freq2 = pq.top().first.second;
            pq.pop();
            pq.push({{sec,freq+freq2},ops+freq});
        }
        return pq.top().second;
    }
};