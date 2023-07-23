class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char>st;
        int m=part.size();
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            if(s[i]==part[m-1]){
                stack<char>temp(st);
                int j=m-1;
                while(j>=0&&!temp.empty()&&temp.top()==part[j]){
                    temp.pop();
                    j--;
                }
                if(j==-1){
                    st=temp;
                }
            }
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};