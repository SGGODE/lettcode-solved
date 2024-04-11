class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(auto&it:num){ 
            while(!st.empty()&&k>0&&it-'0'<st.top()){
                st.pop();
                k--;
            }
            st.push(it-'0');
        }
        while(k>0){
            st.pop();
            k--;
        }
        string x;
        while(!st.empty()){
            x.push_back(st.top()+'0');
            st.pop();
        }
        reverse(x.begin(),x.end());
        string result;
        int i=0;
        while(x[i]=='0'&&i<x.size()){
            i++;
        }
        for(;i<x.size();i++){
            result.push_back(x[i]);
        }
        return result.empty()?"0":result;
    }
};