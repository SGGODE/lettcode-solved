//class LFUCache {
// public:
//     map<int,int>v;
//     map<int,int>mp;
//     int limit=0;
//     LFUCache(int capacity) {
//       limit=capacity;  
//     }
    
//     int get(int key) {
//         if(limit==0)return -1;
//         if(mp.find(key)==mp.end())return -1;
//         v[key]+=1;
//         return mp[key];
//     }
    
//     void put(int key, int value) {
//         if(v.size()<limit){
//           v[key]=1;
//           mp[key]=value;
//         }else{
//            if(mp.find(key)!=mp.end()){
//                v[key]+=1;
//                mp[key]=value;
//            }
//             else{
//            int min_use=INT_MAX;
//            int min_key=INT_MAX;
//            for(auto it:v){
//                if(it.second<min_use){
//                    min_use=it.second;
//                    min_key=it.first;
//                }
//            }
//            // cout<<min_key<<endl;
//            v.erase(min_key);
//            mp.erase(min_key);
//             v[key]=1;
//             mp[key]=value;
//         } 
//         }
//     }
// };
class LFUCache {
public:
    LFUCache(int capacity) {
        size = capacity;
        m.clear();
        mlist.clear();
        mcount.clear();
    }
    
    int get(int key) {
        if(m.count(key)==0)return -1;
        int c = m[key].second;
        mcount[c].erase(mlist[key]);
        if(mcount[c].empty()){
            if(minfreq==c)minfreq++;
        }
        mcount[c+1].push_front(key);
        mlist[key] = mcount[c+1].begin();
        m[key].second++;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if(m.size()==size && m.count(key)==0){
            // evict
            if(size==0)return;
            int k = mcount[minfreq].back();
            m.erase(k);
            mlist.erase(k);
            mcount[minfreq].pop_back();
        }
        if(m.count(key)==0){
            m[key] = {value,1};
            minfreq = 1;
            mcount[1].push_front(key);
            mlist[key] = mcount[1].begin();
        }
        else{
            int c = m[key].second;
            mcount[c].erase(mlist[key]);
            if(mcount[c].empty()){
                if(minfreq==c)minfreq++;
            }
            mcount[c+1].push_front(key);
            mlist[key] = mcount[c+1].begin();
            m[key].first = value;
            m[key].second++;
        }
    }
private:
    int size;
    int minfreq;
    unordered_map<int,pair<int,int>>m;
    unordered_map<int,list<int>>mcount;
    unordered_map<int,list<int>::iterator>mlist;
    
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */