class MapSum {
public:
    MapSum() {
        
    }
    unordered_map<string,int>mp;
    void insert(string key, int val) {
       mp[key]=val; 
    }
    
    int sum(string prefix) {
        int n=prefix.size();
        int total=0;
        for(auto it:mp){
            string s=it.first;
            string x=s.substr(0,n);
            if(x==prefix)total+=it.second;
        }
        return total;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */