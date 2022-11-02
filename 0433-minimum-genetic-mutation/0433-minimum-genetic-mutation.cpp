// class Solution {
// private:
//     bool check(string x,string s){
//         int cnt=0;
//         for(int i=0;i<s.size();i++){
//             if(s[i]!=x[i])cnt++;
//         }
//         if(cnt==1)return 1;
//         return 0;
//     }
//     bool checkstr(string x,string s){
//         int cnt=0;
//         for(int i=0;i<s.size();i++){
//             if(s[i]!=x[i]){
//                 cnt++;
//             }
//         }
//         if(cnt==0)return 1;
//         return 0;
//     }
//     bool checksr(string x,string s){
//         int cnt=0;
//         for(int i=0;i<s.size();i++){
//             if(s[i]!=x[i]){
//                 cnt++;
//             }
//         }
//         if(cnt>=2)return 1;
//         return 0;
//     }
// public:
//     int minMutation(string start, string end, vector<string>& bank) {
//        map<string,int>mp;
//         for(int i=0;i<bank.size();i++){
//             mp[bank[i]]++;
//         }
//         if(mp.find(end)==mp.end()){
//             return -1;
//         }bool flag=0;
//         for(int i=1;i<bank.size();i++){
//             if(checksr(bank[i-1],bank[i])){
//                 flag=1;
//             }
//         }
//         if(flag)
//          sort(bank.begin(),bank.end());
//         string x=start;
//         int cnt=0;
//         for(int j=0;j<8;j++){
//          for(int i=0;i<bank.size();i++){
//             // cout<<1<<endl;
//             if(x==end){
//                // cout<<1<<endl;
//                 return cnt;
//             }
//             if(check(x,bank[i])){
//                 cnt++;
//                 x.clear();
//                 x=bank[i];
//                // cout<<x<<" "<<cnt<<endl;
//             }
//           }
//         }
//         return -1;
//     }
// };
class Solution {
public:
  int minMutation(string start, string end, vector<string>& b) {
    map<string,int> dist;
    dist[start] = 0;
    queue<string> q;
    q.push(start);
    while (q.size()) {
      auto u = q.front(); q.pop();
      for (auto v : b) {
        if (dist.count(v)) continue;
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
          if (u[i] != v[i]) cnt++;
        }
        if (cnt == 1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    if (dist.count(end)) return dist[end];
    else return -1;
  }
}; 