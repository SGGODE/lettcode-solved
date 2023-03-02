class Solution {
public:
    int compress(vector<char>& chars) {
       vector<char>v;
       for(int i=0;i<chars.size();i++){
           int cnt=1;int j=0;
           for(j=i+1;j<chars.size();j++){
               if(chars[i]!=chars[j]){
                   break;
               }
               ++cnt;
           }
           if(cnt==1){
               v.push_back(chars[i]);
           }else{
               v.push_back(chars[i]);
               string s;
               while(cnt!=0){
                   int last=cnt%10;
                   s.append(to_string(last));
                   cnt=cnt/10;
               }
               reverse(s.begin(),s.end());
               for(int k=0;k<s.size();k++){
                   v.push_back(s[k]);
               }
           }
           i=j-1;
       }
        chars.clear();
        chars=v;
        return v.size();
    }
};