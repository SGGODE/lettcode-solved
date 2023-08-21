class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        map<string,int>mp;
        int n = s.size();
         string x;
        for(int i=0;i<s.size()/2;i++){
           // for(int j=i;j<s.size()/2;j++){
                x.push_back(s[i]);
                mp[x]++;
           // }
        }
        for(auto&it:mp){
            string x = it.first;
            string temp=x;
               while(x.size()<=n){
                  if(x==s)return 1;
                  x.append(temp);
                 // ++cnt;
              }
        }
        return 0;
    }
};