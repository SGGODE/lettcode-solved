class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int len = -1;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            int j = s.size()-1;
            while(s[j]!=s[i]&&j>i)--j;
            len = max(len,(j-i)-1);
        }
        return len;
    }
};