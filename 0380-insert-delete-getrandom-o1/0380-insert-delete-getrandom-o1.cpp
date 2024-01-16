class RandomizedSet {
public:
    vector<int>res;
    map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!mp.count(val)){
            int n = res.size();
            mp[val]=n;
            res.push_back(val);
            return 1;
        }
        return 0;
    }
    
    bool remove(int val) {
         if(mp.count(val)){
             int index = mp[val];
             int n = res.size();
             mp[res[n-1]]=index;
             res[index]=res[n-1];
             res.pop_back();
             mp.erase(val);
             return 1;
         }
        return 0;
    }
    
    int getRandom() {
        return res[rand()%res.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */