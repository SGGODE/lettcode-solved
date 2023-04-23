class Solution {
public:
    int secondHighest(string s) {
        set<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0'&&s[i]<='9'){
                st.insert(s[i]-'0');
            }
        }
        if(st.empty())return -1;
        priority_queue<int>pq(st.begin(),st.end());
        pq.pop();
        if(pq.empty())return -1;
        return pq.top();
    }
};