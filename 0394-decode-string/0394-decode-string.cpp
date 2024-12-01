class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(auto & it : s){
            if(it == ']'){
                string temp;
                while(st.top() != '['){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                int len = temp.size();
                string num;
                while(!st.empty() && isdigit(st.top())){
                    num.push_back(st.top());
                    st.pop();
                }
                reverse(num.begin(),num.end());
                //st.pop();
               // cout<<num<<" "<<len<<endl;
                for(int i = 0; i < stoi(num); i++){
                    for(int j = len - 1; j >= 0; j--){
                        st.push(temp[j]);
                    }
                }
            }else{
                st.push(it);
            }
        }
        s.clear();
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};