class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto it:arr)mp[it]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<pair<int,int>>v;
        while(!pq.empty()){
            v.push_back({pq.top().first,pq.top().second});
            pq.pop();
        }
        // for(auto it:v)cout<<it.second<<""<<it.first<<" ";
        // cout<<endl;
        int j=0;
        while(k>0){
           v[j].first-=1;
           if(v[j].first==0)j++;
            --k;
        }
        //  for(auto it:v)cout<<it.second<<""<<it.first<<" ";
        // cout<<endl;
        int cnt=0;
        for(auto it:v){
            if(it.first==0)continue;
            else ++cnt;
        }
        return cnt;
    }
};