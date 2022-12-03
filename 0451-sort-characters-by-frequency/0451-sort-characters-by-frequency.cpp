class Solution {
public:
    string frequencySort(string s) {
      map<char,int>mp;
      for(int i=0;i<s.size();i++){
          mp[s[i]]++;
      }
      vector<pair<int,char>>v;
      for(auto it:mp){
            v.push_back({it.second,it.first});
      }
      sort(v.begin(),v.end());
      int n=v.size();string res;
      for(int i=n-1;i>=0;i--){
          for(int j=0;j<v[i].first;j++){
              res.push_back(v[i].second);
          }
      }
        return res;
    }
};