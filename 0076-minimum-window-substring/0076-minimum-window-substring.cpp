class Solution {
private:
bool compare(map<char,int>&mp,map<char,int>&mx){
    for(auto&it:mp){
       if(!(mx.count(it.first)&&it.second<=mx[it.first])){
         return 0;
       }
    }
  return 1;
}
public:
    string minWindow(string str, string arr) {
        int n = str.size();
          map<char,int>mp;
          for(auto&it:arr)mp[it]++;
          int j = 0;
          int len = INT_MAX;
          int targeti=-1,targetj=-1;
          map<char,int>mx;
          for(int i=0;i<n;i++){
             mx[str[i]]++;
             while(compare(mp,mx)&&j<=i){
                if(len>(i-j)+1){
                   len = (i-j)+1;
                   targeti=i;
                   targetj=j;
                }
                --mx[str[j]];
                if(mx[str[j]]==0)mx.erase(str[j]);
                j++;
             }
          }
          string x;
          if(targeti!=-1&&targetj!=-1)for(int i=targetj;i<=targeti;i++)x.push_back(str[i]);
          return x.empty()?"":x;

    }
};