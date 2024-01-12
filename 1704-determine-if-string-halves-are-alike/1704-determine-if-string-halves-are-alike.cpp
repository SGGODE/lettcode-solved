class Solution {
private:
    bool check(char&ch){
        set<char>st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        return st.count(ch);
    }
public:
    bool halvesAreAlike(string s) {
        int cnt = 0;
        for(auto&it:s){
            if(check(it))++cnt;
        }
        int n = s.size();
        int c2 = 0;
        for(int i=0;i<n/2;i++){
            if(check(s[i]))++c2;
        }
        return (cnt-c2)==c2;
    }
};