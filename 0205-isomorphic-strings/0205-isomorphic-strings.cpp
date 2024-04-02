class Solution {
public:
    bool isIsomorphic(string s, string t) {
          map<char,int>mp,mx;
          for(int i=0;i<s.size();i++){
              if(mp[s[i]]!=mx[t[i]])return 0;
              mp[s[i]]=i+1;
              mx[t[i]]=i+1;
          }
          return 1;
    }
};