class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int n=rooms.size();
      
        queue<int>pq;
        vector<bool>vis(n,0);
        for(auto it:rooms[0])pq.push(it);
       // pq.push()
        set<int>s(rooms[0].begin(),rooms[0].end());
        while(!pq.empty()){
           // if(vis[pq.front()]){
              //  pq.pop();
            //}
            for(auto it:rooms[pq.front()]){
                if(vis[it])continue;
                pq.push(it);
            }
            vis[pq.front()]=1;
            pq.pop();
        }
         for(int i=1;i<n;i++){
            if(!vis[i]){
                //cout<<i<<endl;
                return 0;
            }
        }
        return 1;
    }
};