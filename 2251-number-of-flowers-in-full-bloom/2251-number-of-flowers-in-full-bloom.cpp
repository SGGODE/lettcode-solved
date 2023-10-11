class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(),flowers.end());
       // two soluction with O(n) time and O(max(start,end)) space
       // with O(n*m) time 
       // // int size = 0;
       //  // for(auto&it:flowers)size=max(size,max(it[0],it[1]));
       //  // vector<int>temp(size+1,0);
       //  // for(auto&it:flowers){
       //  //     for(int i=it[0];i<=it[1];i++){
       //  //         temp[i]+=1;
       //  //     }
       //  // }
       int n =people.size();
       vector<int>res(n,0);
       //  for(auto&vt:people){
       //      int cnt =0;
       //     // if(it<size+1)res.push_back(temp[it]);
       //     // else res.push_back(0);
       //      for(auto it:flowers){
       //          if(it[0]<=vt&&it[1]>=vt)++cnt;
       //      }
       //      res.push_back(cnt);
       //  }
        // the optimal one with minimum space and time.
        priority_queue<int,vector<int>,greater<int>>pq;
        priority_queue<int,vector<int>,greater<int>>pqx;
        for(auto&it:flowers){pq.push(it[0]);pqx.push(it[1]);}
        int cnt = 0;
        vector<pair<int,int>>work;int index = 0;
        for(auto&it:people){work.push_back({it,index});++index;}
        sort(work.begin(),work.end());
        for(auto&it:work){
            while(!pq.empty()&&pq.top()<=it.first){
                ++cnt;
                pq.pop();
            }
            while(!pqx.empty()&&pqx.top()<it.first){
                --cnt;
                pqx.pop();
            }
            res[it.second]=cnt;
        }
        return res;
    }
};