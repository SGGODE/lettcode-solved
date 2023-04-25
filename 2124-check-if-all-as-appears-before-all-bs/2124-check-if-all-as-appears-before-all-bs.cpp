class Solution {
public:
    bool checkString(string s) {
       bool flag=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b')flag=1;
            if(s[i]=='a'&&flag)return 0;
        }
        return 1;
    }
};