class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        int len = 0;
        while(ss>>word){
            int x = word.size();
            len = x;
        }
        return len;
    }
};