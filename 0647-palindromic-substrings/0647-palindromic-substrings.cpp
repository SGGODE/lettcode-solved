class Solution {
private:
    bool check(string s){
        int n = s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])return 0;
        }
        return 1;
    }
public:
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            string res;
            for(int j=i;j<s.size();j++){
                res.push_back(s[j]);
                if(check(res))++cnt;
            }
        }
        return cnt;
    }
};