class Solution {
public:
    string reverseWords(string s) {
     stringstream ss(s);
     stack<string>st;
     string word;
    while(ss>>word){
        st.push(word);
    }
    s.clear();
     while(!st.empty()){
         s+=st.top();
         st.pop();
         if(!st.empty())s+=" ";
     }
        return s;
    }
};