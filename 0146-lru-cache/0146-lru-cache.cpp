 class LRUCache {
// public:
//     int size=0;
//     LRUCache(int capacity) {
//         size=capacity;
//     }
//     bool flag=0;
//     vector<int>vx;
//     unordered_map<int,int>mp,mx;
//     int get(int key) {
//         if(mp.count(key)){
//             mx[key]++;
//             vx.push_back(key);
//             return mp[key];
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         if(!mp.count(key)&&size==mp.size()){
//               unordered_map<int,int>temp;
//               for(int i=vx.size()-1;i>=0&&temp.size()<size-1;i--){
//                   temp[vx[i]]++;
//               }
//             int x=0;
//             for(auto&it:mp){
//                 if(!temp.count(it.first)){
//                    x=it.first;
//                 }
//             }
//              mp.erase(x);
//              mx.erase(x);
//                    // break;
//             mp[key]=value;
//             mx[key]++;
//             vx.push_back(key);
//          }else{
//             mp[key]=value;
//             mx[key]++;
//             vx.push_back(key);
//         }
//     }
unordered_map <int, int> m, cnt;
queue <int> q;
int n;
     public:
LRUCache(int capacity) : n(capacity) {}
int get(int key) {
	if (cnt.find(key) == cnt.end()) 
		return -1;
	q.push(key);
	cnt[key]++;
	return m[key];
}
void put(int key, int value) {
	q.push(key);
	cnt[key]++;
	m[key] = value;
	while (cnt.size() > n) {
		int cur = q.front(); q.pop();
		if (cnt[cur]-- == 1) 
			cnt.erase(cur);
	}
}
 };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */