class Solution {
public:
    // int mostBooked(int n, vector<vector<int>>& meetings) {
    //     priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
    //     sort(meetings.begin(),meetings.end());
    //     priority_queue<int>px;
    //     for(int i=0;i<n;i++)px.push(i);
    //     int mp[101]={0};
    //     for(int i=0;i<meetings.size();i++){
    //         while(!pq.empty()&&pq.top().first<=meetings[i][0]){
    //             px.push(pq.top().second);
    //             pq.pop();
    //         }
    //         long long int start = px.empty() ? pq.top().first : meetings[i][0];
    //         long long int dur = meetings[i][1]-meetings[i][0];
    //         int room = px.empty() ? pq.top().second : px.top(); 
    //         if(px.empty())pq.pop();
    //         else px.pop();
    //         ++mp[room];
    //         pq.push({start+dur,room});
    //     }
    //     return max_element(begin(mp),end(mp))-begin(mp);
    // }
    int mostBooked(int n, vector<vector<int>>& meets) {
    int cnt[101] = {};
    sort(begin(meets), end(meets));
    priority_queue<int, vector<int>, greater<int>> avail;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
    for (int i = 0; i < n; ++i)
        avail.push(i);
    for (auto &m : meets) {
        while (!busy.empty() && busy.top().first <= m[0]) {
            avail.push(busy.top().second);
            busy.pop();
        }
        long long start = avail.empty() ? busy.top().first : m[0], duration = m[1] - m[0];
        int room = avail.empty() ? busy.top().second : avail.top();
        if (avail.empty())
            busy.pop();
        else
            avail.pop();
        ++cnt[room];
        busy.push({start + duration, room});
    }
    return max_element(begin(cnt), end(cnt)) - begin(cnt);
}
};