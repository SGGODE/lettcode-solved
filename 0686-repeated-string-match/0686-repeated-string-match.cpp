class Solution {
private:
    bool check(string x,string s){
         if(x.find(s) != string::npos)
           return 1;
        return 0;
    }
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        string x;int cnt=0;
        while(x.size()<=(n+m)){
            x.append(a);
            ++cnt;
            if(check(x,b))return cnt;
        }
        return -1;
    }
};