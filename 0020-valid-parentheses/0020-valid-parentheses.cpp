class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.size()==0)st.push(s[i]);
            else{
                if(s[i]=='}'){
                    if(st.top()!='{')return 0;
                    st.pop();
                }
               else if(s[i]==')'){
                    if(st.top()!='(')return 0;
                    st.pop();
                }
               else if(s[i]==']'){
                    if(st.top()!='[')return 0;
                    st.pop();
                }
              else st.push(s[i]);
            }
        }
        return st.empty();
    }
};