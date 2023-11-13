class Solution {
private:
    bool isVowel(char&ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
    }
public:
    string sortVowels(string s) {
        vector<int>index;
        vector<char>ch;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                index.push_back(i);
                ch.push_back(s[i]);
            }
        }
        sort(ch.begin(),ch.end());
        for(int i=0;i<index.size();i++){
            s[index[i]]=ch[i];
        }
        return s;
    }
};