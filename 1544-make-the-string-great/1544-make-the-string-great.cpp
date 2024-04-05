class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        int n = s.size();
        int i = 1;
        st.push(s[0]);
        while(i<n){
             if(st.empty()){
                 st.push(s[i]);
                 i++;
                 continue;
             }else if(abs(int(st.top())-int(s[i]))==32){
                 st.pop();
             }else{
                 st.push(s[i]);
             }
            i++;
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};