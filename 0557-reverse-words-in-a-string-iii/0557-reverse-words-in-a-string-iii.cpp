class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int size = 0;
        string res;
        string word;
        stringstream ss(s);
        while(ss>>word){
            reverse(word.begin(),word.end());
            res.append(word);
            size+=word.size();
            if(size!=n){
                res.push_back(' ');
                ++size;
            }
        }
        return res;
    }
};