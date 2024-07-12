class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<char>st;
        bool f = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == ')'){
                string temp;
                while(!st.empty() && st.top() !=  '('){
                     temp.push_back(st.top());
                     st.pop();
                }
                st.pop();
                // u(love
                // evol
                //
               for(auto&it:temp){
                   st.push(it);
               }
            }
            else{
            st.push(s[i]);
            }
        }
        string result;
        while(!st.empty()){
            if(st.top()!='(')result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

