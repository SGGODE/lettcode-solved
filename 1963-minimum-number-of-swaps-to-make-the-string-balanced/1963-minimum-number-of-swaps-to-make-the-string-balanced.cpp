class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int cnt = 0;
        stack<char>st;
        int i=0,j=n-1;
        int o=0,e=0;
        while(i<j){
            if(s[i]=='[')++o;
            else ++e;
            if(e>o){
                while(j>i&&s[j]!='[')--j;
                swap(s[i],s[j]);
                --j;
                ++cnt;
                --e;
                ++o;
            }
            i++;
        }
        return cnt;
    }
};