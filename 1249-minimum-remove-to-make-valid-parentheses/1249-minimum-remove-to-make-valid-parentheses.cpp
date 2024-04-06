class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push({'(',i});
            }else if(s[i]==')'){
                if(st.empty())s[i]='.';
                else st.pop();
            }
        }
        while(!st.empty()){
            s[st.top().second]='.';
            st.pop();
        }
        string res;
        for(auto&it:s){
            if(it!='.')res.push_back(it);
        }
        return res;
    }
};