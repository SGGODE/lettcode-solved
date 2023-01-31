class Solution {
private:
      int m=INT_MIN;
    void subseq(vector<int>&scores,vector<int>&ages,int idx,vector<pair<int,int>>&storage,int n){
        if(idx==n){
            for(int i=0;i<storage.size();i++){
                for(int j=0;j<storage.size();j++){
                    if(i==j)continue;
                    else{
                       if(storage[i].first>storage[j].first&&storage[i].second<storage[j].second){
                        return;
                       }
                     if(storage[i].first<storage[j].first&&storage[i].second>storage[j].second){
                        return;
                      }
                    }
                  //  currsum+=v[j].first;
                }
            }
            int sum=0;
            for(auto it:storage){
                sum+=it.first;
            }
            m=max(m,sum);
            return;
        }
        storage.push_back({scores[idx],ages[idx]});
        subseq(scores,ages,idx+1,storage,n);
        storage.pop_back();
        subseq(scores,ages,idx+1,storage,n);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
       //   vector<pair<int,int>>v;
       //  int n=scores.size();
       // subseq(scores,ages,0,v,n);
        vector<pair<int,int>>v;
        for(int i=0;i<scores.size();i++){
            v.push_back({ages[i],scores[i]});
        }
        sort(v.begin(),v.end());
        int max_score=INT_MIN;
        int n=scores.size();
        vector<int>dp(n+1,-1);
        for(int i=0;i<scores.size();i++){
            dp[i]=v[i].second;
            for(int j=i-1;j>=0;j--){
                if(v[i].second>=v[j].second){
                    dp[i]=max(dp[i],dp[j]+v[i].second);
                }
            }
            max_score=max(max_score,dp[i]);
        }
        return max_score;
    }
};