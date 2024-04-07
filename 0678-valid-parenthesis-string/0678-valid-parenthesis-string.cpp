class Solution {
public:
    bool checkValidString(string s) {
         int n = s.size();
         int j = 0;
         int cnt = 0;
         stack<int>st,star;
          for(;j<n;j++){
              if(s[j]==')'){
                 if(!st.empty())st.pop();
                 else if(!star.empty())star.pop();
                 else return 0; 
             }
             else if(s[j]=='(')st.push(j);
             else star.push(j);
        }
        while(!st.empty()&&!star.empty()&&st.top()<star.top()){
            st.pop();
            star.pop();
        }
        return st.empty();
    }
};