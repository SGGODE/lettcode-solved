class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>st;
        for(auto&it:s)st[it]++;
        map<char,int>mx;
        for(auto&it:t){
            if(!st.count(it))return it;
            mx[it]++;
        }
        for(auto&it:mx){
            if(it.second!=st[it.first])return it.first;
        }
        return '-1';
    }
};