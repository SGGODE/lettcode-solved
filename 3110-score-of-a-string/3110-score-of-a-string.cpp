class Solution {
public:
    int scoreOfString(string s) {
        int result = 0;
        for(int i=1;i<s.size();i++){
            result+=abs(int(s[i])-int(s[i-1]));
        }
        return result;
    }
};