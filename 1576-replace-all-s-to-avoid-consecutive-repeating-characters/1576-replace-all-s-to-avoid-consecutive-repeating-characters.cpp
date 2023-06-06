class Solution {
public:
    string modifyString(string s) {
        map<int,char>mp;
        char ch='a';
        mp[1]=ch;
        for(int i=1;i<=25;i++){
            mp[i+1]=ch+i;
        }
        int n=s.size();
        for(int i=0;i<n;i++){
           if(i+1<n&&i>=1&&s[i]=='?'){
               int j=1;
               while(mp[j]==s[i-1]||mp[j]==s[i+1]&&j<26)j++;
               s[i]=mp[j];
           }else{
               if(i==0&&s[i]=='?'){
                   if(i+1<n&&s[i+1]!='?'){
                       if(s[i+1]=='a')s[i]='b';
                       else s[i]='a';
                   }else s[i]='a';
               }else{
                   if(s[i]=='?'){
                    if(i-1>=0&&s[i-1]=='a')s[i]='b';
                    else s[i]='a';
                   }
               }
           }
        }
        return s;
    }
};