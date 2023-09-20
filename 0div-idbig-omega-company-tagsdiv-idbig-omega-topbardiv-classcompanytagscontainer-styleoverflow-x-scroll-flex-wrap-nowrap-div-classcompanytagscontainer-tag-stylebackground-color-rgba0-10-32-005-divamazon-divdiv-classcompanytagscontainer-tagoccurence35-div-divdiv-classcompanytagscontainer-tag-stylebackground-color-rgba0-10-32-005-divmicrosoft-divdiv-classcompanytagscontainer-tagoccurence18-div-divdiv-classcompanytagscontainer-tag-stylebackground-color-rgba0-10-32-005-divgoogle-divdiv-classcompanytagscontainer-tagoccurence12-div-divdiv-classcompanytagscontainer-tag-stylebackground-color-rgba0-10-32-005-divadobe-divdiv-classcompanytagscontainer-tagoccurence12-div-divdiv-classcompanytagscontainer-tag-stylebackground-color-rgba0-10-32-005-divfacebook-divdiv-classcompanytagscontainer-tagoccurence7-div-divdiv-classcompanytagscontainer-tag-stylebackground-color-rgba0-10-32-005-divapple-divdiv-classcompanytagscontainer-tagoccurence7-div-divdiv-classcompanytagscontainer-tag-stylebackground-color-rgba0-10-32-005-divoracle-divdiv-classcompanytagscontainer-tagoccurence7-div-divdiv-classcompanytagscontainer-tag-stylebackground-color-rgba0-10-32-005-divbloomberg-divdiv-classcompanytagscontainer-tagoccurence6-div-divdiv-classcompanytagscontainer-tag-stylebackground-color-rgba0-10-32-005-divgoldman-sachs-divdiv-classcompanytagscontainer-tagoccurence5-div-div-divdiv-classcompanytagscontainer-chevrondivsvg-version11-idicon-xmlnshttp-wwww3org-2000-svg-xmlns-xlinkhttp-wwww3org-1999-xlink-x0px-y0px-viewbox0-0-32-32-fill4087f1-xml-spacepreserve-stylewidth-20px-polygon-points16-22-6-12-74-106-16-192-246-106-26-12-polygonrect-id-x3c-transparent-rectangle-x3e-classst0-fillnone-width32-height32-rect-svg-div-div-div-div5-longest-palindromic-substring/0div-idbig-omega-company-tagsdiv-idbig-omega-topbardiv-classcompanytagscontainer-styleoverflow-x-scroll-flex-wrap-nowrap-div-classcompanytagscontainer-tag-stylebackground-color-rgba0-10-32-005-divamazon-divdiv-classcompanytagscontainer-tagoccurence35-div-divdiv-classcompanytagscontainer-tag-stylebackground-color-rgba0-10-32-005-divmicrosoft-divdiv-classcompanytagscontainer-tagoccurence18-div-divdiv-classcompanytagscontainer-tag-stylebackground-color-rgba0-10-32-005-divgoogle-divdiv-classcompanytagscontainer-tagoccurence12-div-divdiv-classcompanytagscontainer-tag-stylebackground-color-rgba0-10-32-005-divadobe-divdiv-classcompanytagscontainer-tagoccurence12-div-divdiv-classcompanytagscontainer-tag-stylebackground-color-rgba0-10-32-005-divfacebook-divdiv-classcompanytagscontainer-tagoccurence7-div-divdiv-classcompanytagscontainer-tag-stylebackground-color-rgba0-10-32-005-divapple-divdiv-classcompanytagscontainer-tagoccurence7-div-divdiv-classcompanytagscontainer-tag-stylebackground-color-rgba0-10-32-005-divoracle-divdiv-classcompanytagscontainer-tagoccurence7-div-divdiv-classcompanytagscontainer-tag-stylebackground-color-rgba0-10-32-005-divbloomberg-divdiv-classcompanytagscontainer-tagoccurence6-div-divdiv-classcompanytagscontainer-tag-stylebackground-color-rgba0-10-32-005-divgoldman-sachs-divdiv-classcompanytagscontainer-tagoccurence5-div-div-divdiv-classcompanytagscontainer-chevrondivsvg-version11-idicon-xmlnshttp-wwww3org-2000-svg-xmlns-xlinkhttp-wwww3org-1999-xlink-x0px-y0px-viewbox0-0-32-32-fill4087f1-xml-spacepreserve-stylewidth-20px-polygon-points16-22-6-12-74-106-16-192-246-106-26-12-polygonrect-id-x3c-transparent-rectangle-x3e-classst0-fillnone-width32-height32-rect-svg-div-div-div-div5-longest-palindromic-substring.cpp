class Solution {
private:
    bool check(string&x){
        int n = x.size();
        if(n==1)return 1;
        for(int i=0;i<n/2;i++){
            if(x[i]!=x[n-i-1])return 0;
        }
        return 1;
    }
public:
    string longestPalindrome(string s) {
       int n = s.size();
        int len =0;
        string res;
        for(int i=0;i<n;i++){
            string x;
            for(int j=i;j<n;j++){
                 x.push_back(s[j]);
                if(check(x)&&x.size()>len){
                    len=x.size();
                    res=x;
                }
            }
        }
        return res;
    }
};