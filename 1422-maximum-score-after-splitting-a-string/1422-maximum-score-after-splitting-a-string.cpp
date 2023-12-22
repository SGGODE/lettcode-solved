class Solution {
public:
    int maxScore(string s) {
        if(s.size()==2){
            if(s[0]=='0'&&s[1]=='0')return 1;
            if(s[0]=='0'&&s[1]=='1')return 2;
            if(s[0]=='1'&&s[1]=='1')return 1;
            if(s[0]=='1'&&s[1]=='0')return 0;
        }
        int cntone = 0;
        int cntzero = 0;
        for(auto&it:s){
            if(it=='1')++cntone;
        }
        int maxcnt = 0;
        if(s[0]=='1')--cntone;
        else ++cntzero;
        for(int i=1;i<s.size();i++){
            maxcnt = max(maxcnt,(cntone+cntzero));
            if(s[i]=='1')--cntone;
            else ++cntzero; 
        }
        return maxcnt;
    }
};