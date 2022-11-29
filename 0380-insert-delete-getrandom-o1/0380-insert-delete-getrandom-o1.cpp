class RandomizedSet {
private:
     unordered_map<int,int>mp;vector<int>v;
public:
    RandomizedSet() {
        
    }
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            int n=v.size();
            mp[val]=n;
            v.push_back(val);
            return 1;
        }
        return 0;
    }
    
    bool remove(int val) {
       if(mp.find(val)!=mp.end()){
            int n=v.size();
            int idx=mp[val];
            mp[v[n-1]]=idx;
            mp.erase(val);
            v[idx]=v[n-1];
            v.pop_back();
            return 1;
        } 
        return 0;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
      // return 1; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */