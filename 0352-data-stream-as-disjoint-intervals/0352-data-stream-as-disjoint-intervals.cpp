class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    map<int,int>mp;
    void addNum(int value) {
        mp[value]++;
    }
    
    vector<vector<int>> getIntervals() {
        if(mp.empty())return {};
        vector<vector<int>>res;
        vector<int>v;
        for(auto &it:mp){
            v.push_back(it.first);
        }
        int start=v[0];
        int temp=v[0];
        for(int i=1;i<v.size();i++){
            if(temp+1==v[i]){
                temp=v[i];
            }else{
                res.push_back({start,temp});
                start=v[i];
                temp=v[i];
            }
        }
        res.push_back({start,temp});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */