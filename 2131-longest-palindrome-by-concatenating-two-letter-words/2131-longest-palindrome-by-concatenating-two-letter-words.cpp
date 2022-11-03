class Solution {
public:
    int longestPalindrome(vector<string>& v) {
     // int m=INT_MIN;
     // set<string>s(v.begin(),v.end());
     // int cnt=0;
     // for(auto it=s.begin();it!=s.end();it++){
     //   set<string>x=s;
     //   string c=*it,e=*it;
     //   x.erase(*it);
     //   reverse(c.begin(),c.end());
     //   if(x.find(c)!=x.end()){
     //     cnt+=c.size();
     //   }else{
     //     if(e==c){
     //       int b=c.size();
     //       m=max(m,b);
     //     }
     //   }
     // }
     //  if(m==INT_MIN){
     //      return cnt;
     //  }
    // return cnt+m;
        // map<string,int>mp;
        // for(int i=0;i<v.size();i++)mp[v[i]]++;
        // set<string>s(v.begin(),v.end());
        // for(auto it=s.begin();it!=s.end();it++){
        //     string d=*it;
        //     reverse(d.begin(),d.end());
        // }
        map<string,int>mp;
        for(int i=0;i<v.size();i++){
            mp[v[i]]++;
        }
        int cnt=0;bool flag=0;
        for(auto it:mp){
            string x=it.first;string g=x;
            reverse(x.begin(),x.end());
            if(x==g){
                cnt+=it.second/2;
                if(it.second%2)flag=1;
            }else{
                cnt+=min(it.second,mp[x]);mp.erase(x);
            }
        }
        cnt*=4;
        if(flag)cnt+=2;
        return cnt;
    }
};