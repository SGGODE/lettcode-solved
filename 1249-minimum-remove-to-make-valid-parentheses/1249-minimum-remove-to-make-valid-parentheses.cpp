class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<pair<char,int>>ss;
        string st;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
               if(!ss.empty()){
                   ss.pop();
                   st.push_back(s[i]);
               }else st.push_back('.');
            }else if(s[i]=='('){
                ss.push({s[i],i});
                st.push_back(s[i]);
            }else{
                st.push_back(s[i]);
            }
        }
        while(!ss.empty()){
            st[ss.top().second]='.';
            ss.pop();
        }
        string result;
        for(auto&it:st){
            if(it!='.')result.push_back(it);
        }
        return result;
    }
};