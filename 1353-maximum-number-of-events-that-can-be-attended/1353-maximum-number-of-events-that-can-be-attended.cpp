class Solution {
private:
        int sub(vector<int>&dp,vector<vector<int>>&events,vector<bool>vis,int index){
        if(index==events.size()){
            return 0;
        }
       // if(dp[index]!=-1)return dp[index];
        int notpick = sub(dp,events,vis,index+1);
        int pick = 0;
        bool flag = 0;
        for(int i=events[index][1];i<=events[index][0];i++){
            if(!vis[i]){
                vis[i]=1;
                flag=1;
                break;
            }
        }
        if(flag){
            pick = 1 + sub(dp,events,vis,index+1);
        }
        return dp[index]=max(pick,notpick);
    }
public:
    int maxEvents(vector<vector<int>>& events) {
       // vector<vector<int>>dp(n,vector<int>(k+1,-1));
        int n=events.size();
        int m=0;
        for(auto&it:events){
            m=max(m,max(it[0],it[1]));
        }
        vector<vector<int>>temp;
        for(auto&it:events)temp.push_back({it[1],it[0]});
        sort(temp.begin(),temp.end());
        int cnt=0;
        set<int>s;
        for(int i=0;i<=m;i++){
            s.insert(i);
        }
        for(auto&it:temp){
          int start=it[1];int end=it[0];
          auto vt = s.lower_bound(start);
          if(*vt>end||vt==s.end())int flag=2;
          else{
              ++cnt;
              s.erase(vt);
          }
        }
        return cnt;
        //return sub(dp,events,vis,0);
    }
};