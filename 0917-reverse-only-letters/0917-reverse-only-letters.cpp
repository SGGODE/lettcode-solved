class Solution {
public:
    string reverseOnlyLetters(string s) {
        int st=0;
        int e=s.size()-1;
        while(st<e){
            if(!(islower(s[st]))&&!(isupper(s[st]))){
                st++;
                continue;
            }
             if(!(islower(s[e]))&&!(isupper(s[e]))){
                e--;
                continue;
            }
            swap(s[st],s[e]);
            st++;
            e--;
        }
        return s;
    }
};