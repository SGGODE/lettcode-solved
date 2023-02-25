class Solution {
public:
    bool isValid(string s) {
       // for(int i=0;i<s.size();i++){
       //     if(s[i]=='('&&s[i+1]==')'){
       //         i+=1;continue;
       //     }else if(s[i]=='{'&&s[i+1]=='}'){
       //         i+=1;
       //         continue;
       //     }else if(s[i]=='['&&s[i+1]==']'){
       //         i+=1;
       //         continue;
       //     }else return 0;
       // }
       //  return 1;
         stack<char> p;
        unordered_map<char,char> mp={{'(',')'},{'[',']'},{'{','}'}};
        for(char c:s){
            if(mp.find(c)!=mp.end())
                 p.push(c);
            else if(!p.empty()&&mp[p.top()]==c)
                 p.pop();
            else
                return false;
        }
        return p.empty();
    }
};