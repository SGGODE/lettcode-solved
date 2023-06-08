class Solution {
public:
    bool isSameAfterReversals(int num) {
        string s=to_string(num);
        int n=s.size();
        if(n>1&&s[n-1]=='0')return false;
        return 1;
    }
};