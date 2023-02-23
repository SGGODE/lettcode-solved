class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       //  int n=profits.size();
       //  bool flag=0;
       //  for(int i=0;i<n;i++){
       //      if(capital[i]<=w)flag=1;
       //  }
       //  if(!flag)return w;
       //  // long long int cnt=0;
       //  // vector<bool>vis(n,0);
       //  vector<pair<int,int>>pq;
       //  for(int i=0;i<n;i++){
       //      pq.push_back({capital[i],profits[i]});
       //  }
       //  sort(pq.begin(),pq.end());
       //  long long int profit=w; 
       //  // while(k>0){
       //  //     int cur_profit=0;
       //  //     int cur_w=0;
       //  //    for(int i=0;i<n;i++){
       //  //        if(pq[i].first<=w&&cur_profit<pq[i].second&&!vis[i]){
       //  //            cur_profit=pq[i].second;
       //  //            cur_w=i;
       //  //        }
       //  //    } 
       //  //     --k;
       //  //     profit+=cur_profit;
       //  //     w+=cur_profit;
       //  //     vis[cur_w]=1;
       //  // }
       //  // return profit;
       //  //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       //  // for(int i=0;i<n;i++){
       //  //     pq.push({capital[i],profits[i]});
       //  // }
       //  priority_queue<pair<int,int>>zq;
       // int i=0;
       //  while(k!=0&&!pq.empty()){
       //     for(;i<n;i++){
       //      if(w<=pq[i].first)
       //       zq.push({pq[i].first,pq[i].second});
       //    }
       // if(zq.empty())return w;
       //      while((!zq.empty())&&k>0&&zq.top().first<=w){
       //          w+=zq.top().second;
       //          zq.pop();
       //          --k;
       //      }
       //  }
       //  return w;
              int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        int i = 0;
        priority_queue<int> maximizeCapital;
        while (k--) {
           
            while (i < n && projects[i].first <= w) {
                maximizeCapital.push(projects[i].second);
                i++;
            }
            if (maximizeCapital.empty())
                break;
            w += maximizeCapital.top();
            maximizeCapital.pop();
        }
        return w;
    }
};