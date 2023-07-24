class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int prev=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')++cnt;
            if(s[i]==')')--cnt;
            if(cnt==0){
                for(int j=prev+1;j<i;j++){
                    res.push_back(s[j]);
                }
                prev=i+1;
            }
        }
        return res;
    }
};