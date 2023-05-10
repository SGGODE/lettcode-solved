class myComparator {
  public:
    bool operator() (const pair<int,string> &p1, const pair<int,string> &p2) {
      if(p1.first == p2.first) return p1.second < p2.second;
      
      return p1.first > p2.first;
    }
};
class Solution {
private:
    // int checkforme(map<string,int>&mp,vector<pair<int,string>>&number,int index,vector<pair<int,int>>&pattern){
    //     int prev=number[index].first;
    //     pattern.push_back({mp[number[index].second],index});
    //     int i=0;
    //     for(i=index-1;i>=0&&number[i].first==prev;i--){
    //         pattern.push_back({mp[number[i].second],i});
    //     }
    //     sort(pattern.begin(),pattern.end());
    //     return i;
    // }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(auto &it:words)mp[it]++;
         priority_queue<pair<int,string>,vector<pair<int,string>>,myComparator>pq;
        // for(auto &it:mp){
        //     pq.push({it.second,it.first});
        // }
        // vector<pair<int,string>>number;
        // vector<pair<string,int>>lexico;
        // for(auto &it:mp){
        //     number.push_back({it.second,it.first});
        //     lexico.push_back({it.first,it.second});
        // }
        // sort(number.begin(),number.end());
        // sort(lexico.begin(),lexico.end());
        // map<string,int>rank;
        // for(int i=0;i<lexico.size();i++){
        //     rank[lexico[i].first]=i;
        //    // cout<<lexico[i].first<<endl;
        // }
        // int n=number.size();
        // bool flag=0;
       // vector<string>res;
        // for(int i=n-1;i>=0&&k>0;i--){
        //     if(i>=1&&number[i].first==number[i-1].first){
        //         flag=1;
        //         vector<pair<int,int>>pattern;
        //         int index=checkforme(rank,number,i,pattern);
        //         i-=(i-index);
        //        // k-=index;
        //         for(int j=0;j<pattern.size()&&k>0;j++){
        //             res.push_back(number[pattern[j].second].second);
        //             --k;
        //         }
        //     }else{
        //         flag=0;
        //         res.push_back(number[i].second);
        //         --k;
        //     }
        // }
        // return res;
        for(auto &it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k)pq.pop();
        }
        vector<string>res(k);
        --k;
        while(!pq.empty()){
           res[k]=pq.top().second;
            --k;
            pq.pop();
        }
        return res;
    }
};