class Solution {
bool check(string s){
    return s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u'||s[0]=='A'||s[0]=='E'||s[0]=='I'||s[0]=='O'||s[0]=='U';
}
int num(string s){
    int cnt=0;
    stringstream ss(s);
    string word;
    while(ss>>word)++cnt;
    return cnt;
}
public:
    string toGoatLatin(string s) {
        string res;
        stringstream ss(s);
        int cnt=1;
        int n=num(s);
        string word;
        while(ss>>word){
            string x;
            if(check(word)){
                x=word;
                x.append("ma");
                for(int i=0;i<cnt;i++)x.push_back('a');
            }else{
                for(int i=1;i<word.size();i++)x.push_back(word[i]);
                x.push_back(word[0]);
                x.append("ma");
                for(int i=0;i<cnt;i++)x.push_back('a');
            }
            ++cnt;
            res.append(x);
            if(cnt<=n)res.append(" ");
        }
        return res;
    }
};