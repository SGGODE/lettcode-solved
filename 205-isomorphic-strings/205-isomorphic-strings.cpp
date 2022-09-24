class Solution {
private:
    bool help(string s,string t){
        map<char,char>mp;
        for(int i=0;i<s.size();i++){
            if(!mp.count(s[i])){
                mp.insert({s[i],t[i]});
            }else{
                if(mp[s[i]]!=t[i]){
                    return 0;
                }
            }
        }
        return 1;
    }
public:
    bool isIsomorphic(string s, string t) {
       if(s.empty())
           return 0;
        else
            return help(s,t)&&help(t,s);
    }
};