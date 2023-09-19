class Solution {
public:
    int maxPower(string s) {
        int len = 0;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                int j = i-1;
                while(j<s.size()&&s[i]==s[j]){
                    ++j;
                }
                len = max(len,(j-i)+1);
            }
        }
        return len==0?1:len;
    }
};