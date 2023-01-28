class SummaryRanges {
public:
    set<int>mp;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        mp.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int>v(mp.begin(),mp.end());
        //for(auto)
        vector<vector<int>>result;
        int j=v[0];
        int start=j;
        if(v.size()==1){
            return {{v[0],v[0]}};
        }
        for(int i=1;i<v.size();i++){
            if(v[i]==j+1){
                j=v[i];
               // continue;
            }else{
                result.push_back({start,j});
                start=v[i];
                j=v[i];
            }
        }
        result.push_back({start,j});
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */